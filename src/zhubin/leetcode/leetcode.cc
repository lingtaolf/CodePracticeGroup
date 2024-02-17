#include "leetcode.h"
#include <algorithm>
#include <cstdint>
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

int Solution::candy(vector<int> &ratings) {
  int n = ratings.size();
  //每个孩子至少一个糖果
  vector<int> candies(n, 1);
  //模拟比较，比左边大的多发一个，比右边大的多发一个
  for (int i = 1; i < n; i++) {
    if (ratings[i] > ratings[i - 1]) {
      // 右边比左边
      candies[i] = candies[i - 1] + 1;
    }
  }
  for (int j = n - 1; j > 0; j--) {
    if (ratings[j - 1] > ratings[j]) {
      // 左边比右边
      // 注意此时的已经更新过了candies，所以要去max ,避免无效的增长
      candies[j - 1] = std::max(candies[j] + 1, candies[j - 1]);
    }
  }

  int sum = std::accumulate(candies.begin(), candies.end(), 0);
  return sum;
}
bool Solution::lemonadeChange(vector<int> &bills) {
  //维护两个变量，5元和10元，碰到20元优先使用10元
  int five = 0, ten = 0;
  for (int bill : bills) {
    switch (bill) {
    case 5:
      five++;
      break;
    case 10:
      if (five <= 0)
        return false;
      ten++;
      five--;
      break;
    case 20:
      if (five > 0 && ten > 0) {
        ten--;
        five--;
      } else if (five >= 3) {
        five -= 3;
      } else {
        return false;
      }
      break;
    }
  }
  return true;
}

vector<vector<int>> Solution::reconstructQueue(vector<vector<int>> &people) {
  // 先按照身高排序，由于个子高的看不到个子矮的，所以矮的可以插队，不影响个子高的属性
  std::function<bool(const vector<int>, const vector<int>)> cmp =
      [](const vector<int> a, vector<int> b) -> bool {
    if (a[0] == b[0])
      return a[1] < b[1];
    return a[0] > b[0];
  };
  std::sort(people.begin(), people.end(), cmp);
  vector<vector<int>> ans;
  for (int i = 0; i < people.size(); i++) {
    int position = people[i][1];
    ans.insert(ans.begin() + position, people[i]);
  }
  return ans;
}

int Solution::findMinArrowShots(vector<vector<int>> &points) {
  //排序
  std::function<bool(const vector<int>, const vector<int>)> cmp =
      [](const vector<int> a, const vector<int> b) -> bool {
    return a[0] < b[0];
  };
  std::sort(points.begin(), points.end(), cmp);
  int result = 1;
  for (int i = 1; i < points.size(); i++) {
    if (points[i][0] > points[i - 1][1]) {
      //不重叠，需要增加一只箭
      result++;
    } else {
      //跟新重叠气球的的右边的边界
      points[i][1] = std::min(points[i - 1][1], points[i][1]);
    }
  }
  return result;
}
int Solution::eraseOverlapIntervals(vector<vector<int>> &intervals) {
  // 排序
  std::function<bool(const vector<int>, const vector<int>)> cmp =
      [](const vector<int> a, const vector<int> b) -> bool {
    return a[1] < b[1];
  };
  std::sort(intervals.begin(), intervals.end(), cmp);
  int count = 1;
  //计算非交叉区间的数目，然后用n减去非交叉区间的数据，就得到需要移除的区间的数目
  int x_end = intervals[0][1];
  for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] >= x_end) {
      count++;
      x_end = intervals[i][1];
    }

    return intervals.size() - count;
  }
}

} // namespace leetcode