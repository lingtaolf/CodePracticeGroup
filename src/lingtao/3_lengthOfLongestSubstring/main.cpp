#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 1)
            return 1; 
        unordered_map<char, int> tmp_str;
        int max_length = 0;
        for (int i = 0; i < s.size(); i++){
            unordered_map<char,int>::iterator it = tmp_str.find(s[i]);
            if (it != tmp_str.end())
            {
                max_length = max_length > tmp_str.size()? max_length:tmp_str.size(); 
                tmp_str.erase(tmp_str.begin(), tmp_str.end());
                i = it->second+1;
            }
            tmp_str.emplace(std::make_pair(s[i], i));
        } 
        max_length =max_length > tmp_str.size()? max_length:tmp_str.size(); 
        return max_length;
    }
};

int main(){
    string s = "abcabcbb";
    cout<<s.size()<<endl;
    Solution sl;
    cout<<sl.lengthOfLongestSubstring(s)<<endl;
    return 0;
}