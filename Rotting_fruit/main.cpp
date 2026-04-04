class Solution {
public:

    int dfs(vector<pair<int,int>>& startNodes, vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        int counter = 0;
        for(auto p : startNodes) q.push(p);

        while (!q.empty()){

          int size = q.size();


          bool s= false;

          for(int i = 0 ; i < size; i++){

          
          auto r = q.front();
          q.pop();

          int i_=r.first;
          int j_=r.second;
          
            vector<vector<int>> path = {
                {0, 1}, 
                {0, -1}, 
                {1, 0}, 
                {-1, 0}
            };

            for (auto p:path){
                int next_i = i_ + p[0];
                int next_j = j_ + p[1];
                if (next_i >= 0 && next_i < grid.size() &&
                        next_j >= 0 && next_j < grid[0].size() &&
                        grid[next_i][next_j] == 1) {
                            grid[next_i][next_j] = 2;
                            q.push({next_i,next_j});
                            s = true;
                        }
            }
        }
        if (s){
            counter +=1;
            }
        }
        return counter;
    }


    int orangesRotting(vector<vector<int>>& grid) {

        vector<pair<int,int>> rottens;
        int total = 0;
        bool found_r = false;
        bool found_f = false;
        for (int i = 0; i <grid.size();i++){
            for (int j = 0; j <grid[0].size();j++){
                if (grid[i][j] == 2){
                    rottens.push_back({i, j});
                    found_r = true;
                }
                if (grid[i][j] == 1){
                    total +=1;
                    found_f = true;
                }
            }
        }
        if (!found_r){
            if (found_f){
            return -1;
            }else{
                return 0;
            }
        }

        int time = dfs(rottens,grid);
        
        for (int i = 0; i <grid.size();i++){
            for (int j = 0; j <grid[0].size();j++){
                
                if (grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return time;
    }   
};
