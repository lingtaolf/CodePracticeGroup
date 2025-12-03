class Solution:
    @classmethod
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == "":
            return 0
        window_start = 0
        window_size = 1
        window_end = window_start + window_size
        longest_size = window_end - window_start
        sub_str = s[window_start:window_end]

        while(window_end < len(s)):
            c = s[window_end]

            if c in sub_str:
                c_index_of_sub_str = sub_str.find(c)
                window_start = window_start + c_index_of_sub_str + 1

            window_end = window_end + 1
            sub_str = s[window_start:window_end]

            current_size = window_end - window_start
            longest_size = current_size if current_size > longest_size else longest_size

        return longest_size


if __name__ == '__main__':
    s = 'abcabcbb'
    print(Solution.lengthOfLongestSubstring(s))
