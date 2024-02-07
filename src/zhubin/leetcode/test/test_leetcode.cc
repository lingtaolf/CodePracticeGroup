#include <cstdio>
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "leetcode.h"

leetcode::Solution *solution = new leetcode::Solution();
TEST_CASE("TestHelloWord") { printf("hello word\n"); };

TEST_CASE("TestvalidPath") {
  int n = 3;
  int source = 0;
  int destination = 2;
  vector<vector<int>> edges({{0, 1}, {1, 2}, {2, 0}});
  bool valid = solution->validPath(n, edges, 0, 2);
  CHECK(valid == true);
};
