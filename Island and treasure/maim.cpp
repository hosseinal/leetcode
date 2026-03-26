class Solution {
public:

    int search(vector<vector<int>>& grid, int row, int col){
        
        int ROW = grid.size();
        int COL = grid[0].size();
        
        std::queue<std::pair<int,int>> tresures;
        std::vector<std::vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        std::vector<std::vector<int>> visited(ROW,std::vector<int>(COL,0));

        int current_step = 0;
        
        tresures.push({row,col});
        
        while (tresures.size() != 0){
            int size = tresures.size();
            
            for (int i = 0; i < size ; i++){
                std::pair p = tresures.front();
                tresures.pop();
                int row = p.first;
                int col = p.second;
                if (grid[row][col] == 0) return current_step;
                for (int i = 0; i < 4 ; i++){
                    
                    int r = row + directions[i][0];
                    int c = col + directions[i][1];

                    if (r < ROW && r >= 0 && c < COL && c >= 0 && !visited[r][c] && grid[r][c] != -1){
                        visited[r][c] = true;
                        tresures.push({r,c});
                    }
                }
            }    

            current_step = current_step + 1; 
        }
        return INT_MAX;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        std::queue<std::pair<int,int>> tresures;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0 ; j < grid[0].size(); j++){
                if (grid[i][j] == INT_MAX){
                    grid[i][j] = search(grid,i,j);
                } 
            }
        }

    }
};

