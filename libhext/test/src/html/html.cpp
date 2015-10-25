// Copyright 2015 Thomas Trapp
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "helper/common.h"

TEST(Html_Html, ExampleFromDocumentation)
{
  Html page("<html><body>This is a string containing html</body></html>");
  const GumboNode * root = page.root();
  EXPECT_TRUE(root);

  Rule html_root(HtmlTag::HTML);
  EXPECT_TRUE(html_root.matches(root));
}
