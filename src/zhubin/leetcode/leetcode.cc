#include "leetcode.h"
#include <functional>
#include <locale>
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

} // namespace leetcode