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

TEST_CASE("TestReconstructQueue") {
  vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  vector<vector<int>> ans = {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
  vector<vector<int>> output = solution->reconstructQueue(people);
  CHECK_EQ(output, ans);
  // for (auto s : output) {
  //   printf("%d==%d\n", s[0], s[1]);
  // }
}