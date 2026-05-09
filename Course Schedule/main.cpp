class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < numCourses; i++) {
            graph[i] = {};
        }

        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> visited(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(visited, graph, i)) {
                    return false;
                }
            }
        }
    
        return true;
    }

    bool dfs(vector<int> &visited, unordered_map<int, vector<int>>& graph, int start) {
        
        if (visited[start] == 1) {
            return false; 
        }

        if (visited[start] == 2) {
            return true; 
        }

        visited[start] = 1; 
        for (int i = 0; i < graph[start].size(); i++) {
            int node = graph[start][i];

            if (!dfs(visited, graph, node)) {
                return false;
            }
        }

        visited[start] = 2; 
        return true;
    }
};
