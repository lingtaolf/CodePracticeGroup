#include "leetcode.h"
#include <functional>
#include <locale>
#include <numeric>
#include <type_traits>
#include <utility>

namespace leetcode {

int Solution::numIslands(vector<vector<char>> &grid) {
  int m = grid.size();
  int n = grid[0].size();
  int nums = 0;
  // bfs 从每个节点开始搜索，找到所有的1，在从下个节点开始，搜索，计数器加1
  vector<vector<int>> visited(m, vector<int>(n));
  std::function<void(int, int)> bfs = [&](int x, int y) {
    std::queue<std::pair<int, int>> que;
    que.emplace(x, y);
    while (!que.empty()) {
      std::pair<int, int> located = que.front();
      int i = located.first, j = located.second;
      que.pop();
      visited[i][j] = 1;
      // TODO visited使用集合unordered_set,就不会有重复问题
      //加入上下左右四个位置枚举一下（i，j+1）（i，j-1）,(i-1,j),(i+1,j)
      if (j + 1 < n && grid[i][j + 1] == '1' && visited[i][j + 1] == 0) {
        que.emplace(i, j + 1);
        visited[i][j + 1] = 1;
      }
      if (j - 1 >= 0 && j - 1 < n && grid[i][j - 1] == '1' &&
          visited[i][j - 1] == 0) {
        que.emplace(i, j - 1);
        visited[i][j - 1] = 1;
      }
      if (i - 1 > 0 && i - 1 < m && grid[i - 1][j] == '1' &&
          visited[i - 1][j] == 0) {
        que.emplace(i - 1, j);
        visited[i - 1][j] = 1;
      }
      if (i + 1 < m && grid[i + 1][j] == '1' && visited[i + 1][j] == 0) {
        que.emplace(i + 1, j);
        ////此处添加标记是为了减少时间，避免元素重复添加
        visited[i + 1][j] = 1;
      }
    }
  };

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '1' and visited[i][j] == 0) {
        nums++;

        bfs(i, j);
      }
    }
  }
  return nums;
}

bool Solution::validPath(int n, vector<vector<int>> &edges, int source,
                         int destination) {
  // // 并查集构建
  // // father数组
  // std::vector<int> father(n, 0);
  // //并查集初始化
  // for (int i = 0; i < n; i++) {
  //   father[i] = i;
  // }
  // // find
  // std::function<int(int)> find = [&](int u) -> int {
  //   return u == father[u] ? u : father[u] = find(father[u]);
  // };
  // // merge 合并
  // std::function<void(int, int)> merge = [&](int i, int j) {
  //   int fa_i = find(i);
  //   int fa_j = find(j);
  //   father[fa_i] = fa_j;
  // };
  // //并查集的三要素

  // for (int i = 0; i < edges.size(); i++) {
  //   merge(edges[i][0], edges[i][1]);
  // }

  // int father_d = find(destination);
  // int father_s = find(source);

  // return father_d == father_s ? true : false;
  UnionFind union_find = UnionFind(n);
  for (int i = 0; i < edges.size(); i++) {
    union_find.merge(edges[i][0], edges[i][1]);
  }
  int father_d = union_find.find(destination);
  int father_s = union_find.find(source);

  return father_d == father_s ? true : false;
}

int Solution::canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  int total_gas = std::accumulate(gas.begin(), gas.end(), 0);
  int total_cost = std::accumulate(cost.begin(), cost.end(), 0);
  if (total_gas < total_cost)
    // 提前返回
    return -1;

  int start = 0;        //起始位置
  int current_left = 0; //当前油箱的剩余油量
  for (int i = 0; i < gas.size(); i++) {
    int left = gas[i] - cost[i];
    current_left += left;
    if (current_left < 0) {
      start = i + 1;
      current_left = 0;
    }
  }
  return start;
}

} // namespace leetcode