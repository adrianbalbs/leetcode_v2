class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        ans = []
        self.dfs(nums, ans, [], 0)
        return ans

    def dfs(self, nums: list[int], ans: list[list[int]], curr: list[int], i: int):
        if i == len(nums):
            ans.append(curr.copy())
            return
        curr.append(nums[i])
        self.dfs(nums, ans, curr, i + 1)
        curr.pop()
        self.dfs(nums, ans, curr, i + 1)
