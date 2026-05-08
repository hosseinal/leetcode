class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }

        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < n; i++) {
            graph[i] = {};
        }

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> visited(n, 0);
        stack<pair<int, int>> valstack;

        valstack.push({0, -1});

        while (!valstack.empty()) {
            int val = valstack.top().first;
            int pa = valstack.top().second;
            valstack.pop();

            if (visited[val]) {
                return false;
            }

            visited[val] = true;

            for (int j = 0; j < graph[val].size(); j++) {
                int nei = graph[val][j];

                if (nei == pa) {
                    continue;
                }

                valstack.push({nei, val});
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }
};
