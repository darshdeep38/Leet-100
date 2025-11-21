class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Build adjacency list and indegree array
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &p : prerequisites) {
            int course = p[0];
            int pre = p[1];
            adj[pre].push_back(course); 
            indegree[course]++;
        }

        // Step 2: Push all courses with indegree 0 into queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: BFS
        int count = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;

            for (int next : adj[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // If we processed all courses → possible
        return count == numCourses;
    }
};
