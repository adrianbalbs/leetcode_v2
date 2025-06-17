class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        in_window = set()
        lo = 0
        ans = 0
        for hi in range(len(s)):
            while s[hi] in in_window:
                in_window.remove(s[lo])
                lo += 1
            in_window.add(s[hi])
            ans = max(ans, hi - lo + 1)

        return ans
