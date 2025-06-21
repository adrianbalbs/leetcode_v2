from collections import deque
from typing import List


# here we use kahn's algo which is similar to bfs, we track in-degrees
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # build graph
        dep_graph = [[] for _ in range(numCourses)]
        # track in degrees
        in_degrees = [0] * numCourses
        for u, v in prerequisites:
            dep_graph[v].append(u)
            in_degrees[u] += 1

        q = deque()
        for v in range(len(in_degrees)):
            if in_degrees[v] == 0:
                q.append(v)

        top_order = []
        while q:
            v = q.popleft()
            top_order.append(v)
            for nei in dep_graph[v]:
                in_degrees[nei] -= 1
                if in_degrees[nei] == 0:
                    q.append(nei)

        return top_order if len(top_order) == numCourses else []
