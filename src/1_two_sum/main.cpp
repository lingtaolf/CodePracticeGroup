#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int, int> nums_map;

        for (int i = 0; i < nums.size(); i++) 
        {
           nums_map[nums[i]] = i;
        }

        for (int i=0; i < nums.size(); i++)
        {
            int need = target - nums[i];
            auto iter = nums_map.find(need); 
            if (iter != nums_map.end())
            {
                if (iter->second == i)
                    continue;
                return {i, iter->second};
            }
        }

        return {};
    }

};


int main()
{
    vector<int> nums = {3, 2, 4};
    int taget = 6;
    Solution s;
    vector<int> res = s.twoSum(nums, taget);
    for (auto it = res.begin(); it != res.end(); it++)
    {
        cout<<*it<<endl; 
    }
}