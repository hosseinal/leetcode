class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        int counter = 0;

        for(int i = 0 ; i < edges.size(); i++){
            auto e = edges[i];

            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int i = 0 ; i < n; i++){
            if(!visited[i]){
                search(adj,visited,i);
                counter++;
            }
        }

        return counter;
    }

    void search (vector<vector<int>>& ad, vector<bool> &visited, int n){
        int size = ad[n].size();
        visited[n] = true;
        for (int i = 0 ; i < size; i++){
            if(!visited[ad[n][i]]){
                search(ad,visited,ad[n][i]);
            }
        }
    }
};

