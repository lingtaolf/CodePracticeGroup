#include <cstdio>
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"
#include "leetcode.h"

leetcode::Solution *solution = new leetcode::Solution();
TEST_CASE("test hello word") {
    printf("hello word");
};