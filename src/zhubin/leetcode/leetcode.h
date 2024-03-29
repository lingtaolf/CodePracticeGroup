#ifndef LEET_CODE_H

#define LEET_CODE_H
#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <stdint.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using std::vector;

namespace leetcode {

//并查集实现
class UnionFind {
public:
  //构造函数
  UnionFind(int n) : father(n), rank(n, 0) {
    for (int i = 0; i < n; i++) {
      father[i] = i;
    }
  }
  int find(int x) { return x == father[x] ? x : father[x] = find(father[x]); }
  void merge(int x, int y) {
    int father_x = find(x);
    int father_y = find(y);
    if (father_x == father_y)
      return;
    if (rank[father_x] < rank[father_y]) {
      father[father_x] = father_y;
    } else if (rank[father_x] > rank[father_y]) {
      father[father_y] = father_x;
    } else {
      // 若两棵树高度相同，则合并后提升任意一棵树的高度
      father[father_x] = father_y;
      rank[father_x]++;
    }
  }

private:
  vector<int> father;
  vector<int> rank; // 存储每个集合（或树）的高度
};

class Solution {
public:
  //=======================广度搜索=======
  // 200. 岛屿数量
  int numIslands(vector<vector<char>> &grid);

  //====================并查集=========
  // 1971. 寻找图中是否存在路径
  // https://leetcode.cn/problems/find-if-path-exists-in-graph/description/
  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination);

  //==================贪心算法===========================
  // 134. 加油站
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost);
  // 135. 分发糖果
  int candy(vector<int> &ratings);
  // 860. 柠檬水找零
  bool lemonadeChange(vector<int> &bills);
  // 406.根据⾝⾼重建队列
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people);
  // 452. 用最少数量的箭引爆气球
  int findMinArrowShots(vector<vector<int>> &points);
  // 435. 无重叠区间
  int eraseOverlapIntervals(vector<vector<int>> &intervals);
  // 763. 划分字母区间
  vector<int> partitionLabels(std::string s);
  // ============滑动窗口===========================
  // 3. 无重复字符的最长子串
  int lengthOfLongestSubstring(std::string s);

  //=====================leetcode top100===================
  // 438. 找到字符串中所有字母异位词
  vector<int> findAnagrams(std::string s, std::string p);
  // 560. 和为 K 的子数组
  int subarraySum(vector<int> &nums, int k);
};

} // namespace leetcode
#endif