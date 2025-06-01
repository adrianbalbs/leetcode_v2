#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses);
        for (auto &pre : prerequisites)
            courses[pre[0]].push_back(pre[1]);
        vector<int> visited(numCourses);

        for (int course = 0; course < numCourses; course++) {
            if (visited[course] == 0 && dfs(course, courses, visited))
                return false;
        }
        return true;
    }

    bool dfs(int course, vector<vector<int>>& courses, vector<int>& visited) {
        if (visited[course] == 2)
            return true;
        if (visited[course] == 1)
            return false;
        visited[course] = 2;
        for (auto &nei : courses[course]) {
            if (dfs(nei, courses, visited))
                return true;
        }
        visited[course] = 1;
        return false;
    }
};
