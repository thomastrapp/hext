#include "hext/Hext.h"

#include "htmlext/ErrorOutput.h"
#include "htmlext/File.h"
#include "htmlext/Json.h"
#include "htmlext/PrintDot.h"
#include "htmlext/ProgramOptions.h"
#include "htmlext/Version.h"

#include <cassert>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <memory>
#include <string>
#include <vector>


int main(int argc, const char ** argv)
{
  std::ios_base::sync_with_stdio(false);

  htmlext::ErrorOutput errout(/* error_source: */ argv[0]);
  htmlext::ProgramOptions po;

  try
  {
    po.store_and_validate_or_throw(argc, argv);

    if( po.contains("help") )
    {
      po.print(argv[0], std::cout);
      return EXIT_SUCCESS;
    }

    if( po.contains("version") )
    {
      htmlext::PrintVersion(std::cout);
      return EXIT_SUCCESS;
    }

    if( po.contains("print-html-dot") )
    {
      std::string file = po.get("print-html-dot");
      std::string html = htmlext::ReadFileOrThrow(file);
      htmlext::PrintHtmlDot(hext::Html(html.c_str(), html.size()), std::cout);
      return EXIT_SUCCESS;
    }

    std::vector<hext::Extractor> extractors;
    std::vector<std::string> html_contents;
    std::vector<hext::Html> parsed_html;
    auto hext_filenames = po.get_hext_files();
    auto hext_inputs = po.get_hext_input();

    assert((hext_filenames.size() + hext_inputs.size()) > 0);
    extractors.reserve(hext_filenames.size() + hext_inputs.size());

    for(const auto& filename : hext_filenames)
      try {
        extractors.emplace_back(htmlext::ReadFileOrThrow(filename));
      } catch( const hext::SyntaxError& e ) {
        errout.print(std::string("Error in " + filename), e.what());
        return EXIT_FAILURE;
      }

    for(const auto& hext_input : hext_inputs)
      try {
        extractors.emplace_back(hext_input);
      } catch( const hext::SyntaxError& e ) {
        errout.print("Error in <hext-string>", e.what());
        return EXIT_FAILURE;
      }

    if( po.contains("lint") )
      return EXIT_SUCCESS;

    auto html_filenames = po.get_html_input();
    parsed_html.reserve(html_filenames.size());
    html_contents.reserve(html_filenames.size());
    for(const auto& filename : html_filenames)
    {
      html_contents.emplace_back(htmlext::ReadFileOrThrow(filename));
      parsed_html.emplace_back(
          html_contents.back().c_str(),
          html_contents.back().size());
    }

    for(const auto& hext : extractors)
      for(const auto& html : parsed_html)
      {
        hext::Result result = hext.extract(html);
        htmlext::PrintJson(result, po.get_json_options(), std::cout);
      }
  }
  catch( const htmlext::FileError& e )
  {
    errout.print("Error", e.what());
    return EXIT_FAILURE;
  }
  catch( const boost::program_options::error& e )
  {
    errout.print("Argument error", e.what());
    // if no options were given at all, print --help
    if( argc < 2 )
    {
      std::cerr << "\n";
      po.print(argv[0], std::cerr);
    }
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

