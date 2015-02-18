#include <cassert>
#include <cstdlib>
#include <iostream>
#include <ios>

#include "hext/parser.h"
#include "hext/html.h"
#include "hext/program-options.h"


int main(int argc, const char ** argv)
{
  std::ios_base::sync_with_stdio(false);

  hext::program_options po(argc, argv);

  if( po.contains("help") )
  {
    po.print(argv[0], std::cout);
    return EXIT_SUCCESS;
  }

  if( !po.validate_or_print_error(std::cerr) )
    return EXIT_FAILURE;

  try
  {
    auto rules = hext::parser::parse_file(po.get("hext-file"));

    if( po.contains("print") )
    {
      for(const auto& r : rules)
        r.print();
      return EXIT_SUCCESS;
    }

    if( po.contains("lint") )
      return EXIT_SUCCESS;

    std::string html_buffer;
    {
      std::ifstream file(po.get("html-file"), std::ios::in | std::ios::binary);

      if( !file )
      {
        std::cerr << "failed opening html-file\n";
        return EXIT_FAILURE;
      }

      file.seekg(0, std::ios::end);
      html_buffer.resize(file.tellg());
      file.seekg(0, std::ios::beg);
      file.read(&html_buffer[0], html_buffer.size());
    }

    hext::html html(html_buffer.c_str(), html_buffer.size());

    for(const auto& rule : rules)
    {
      std::unique_ptr<hext::match_tree> mt = html.extract(rule);
      assert(mt != nullptr);

      if( !po.contains("keep-invalid") )
        mt->filter();

      if( po.contains("print-debug") )
      {
        rule.print(std::cout, 0, true);
      }
      else if( po.contains("mt-graph") )
      {
        mt->print_dot();
      }
      else
      {
        mt->print_json();
      }
    }
  }
  catch( std::ios_base::failure& e )
  {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

