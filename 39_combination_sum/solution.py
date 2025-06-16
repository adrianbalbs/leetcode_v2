class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        ans = []
        self.dfs(candidates, ans, [], 0, target)
        return ans

    def dfs(
        self,
        candidates: list[int],
        ans: list[list[int]],
        curr: list[int],
        i: int,
        target: int,
    ):
        if target == 0:
            ans.append(curr.copy())
            return
        if i == len(candidates) or target < 0:
            return

        curr.append(candidates[i])
        self.dfs(candidates, ans, curr, i, target - candidates[i])
        curr.pop()
        self.dfs(candidates, ans, curr, i + 1, target)
