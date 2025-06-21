from typing import List


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(numCourses)]
        vis = [0] * numCourses
        for u, v in prerequisites:
            graph[v].append(u)
        top_order = []

        def dfs(course: int) -> bool:
            if vis[course] == 2:
                return False
            if vis[course] == 1:
                return True
            vis[course] = 2
            for nei in graph[course]:
                if not dfs(nei):
                    return False
            vis[course] = 1
            top_order.append(course)
            return True

        for v in range(numCourses):
            if not dfs(v):
                return []

        return list(reversed(top_order))
