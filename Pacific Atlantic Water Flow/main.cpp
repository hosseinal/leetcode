class Solution {
public:

    void dfs(vector<vector<int>>heights, vector<vector<int>> &visited_map, int i, int j){
        int rows = heights.size();
        int cols = heights[0].size();
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        stack <pair<int, int>> s ={};
        s.push({i ,j});
        visited_map[i][j] = 1;
        while (s.size()!= 0){

            auto a = s.top(); 
            s.pop();
            int row = a.first;
            int col = a.second;

            for (pair dir : directions){
                int nrow = row + dir.first;
                int ncol = col + dir.second;
                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && !visited_map[nrow][ncol] && heights[nrow][ncol] >= heights[row][col]) {
                    visited_map[nrow][ncol] = 1;
                    s.push({nrow ,ncol});
                }
                
            }
            
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        vector<vector<int>> results;
         int rows = heights.size();
         int cols = heights[0].size();

        vector<vector<int>> visited_pacific(rows,vector<int>(cols,0));
        vector<vector<int>> visited_atlantic(rows,vector<int>(cols,0));

        
        // check for atlantic
        
        for (int i = 0; i < cols; i ++){
            // dfs on [0][i]
            dfs(heights,visited_atlantic,0,i);
        }

        for (int i = 0; i < rows; i ++){
            // dfs on [i][0]
            dfs(heights,visited_atlantic,i,0);
        }


        // check for pacific
        
        for (int i = 0; i < cols; i ++){
            dfs(heights,visited_pacific, rows-1, i);
        }

        for (int i = 0; i < rows; i ++){
            dfs(heights,visited_pacific, i, cols-1);
        }


        // chech thse that both can gets to water.

        for (int i = 0 ; i < rows ; i++){
            for (int j = 0 ; j < cols ; j++){
                if (visited_atlantic[i][j] && visited_pacific[i][j]){
                    results.push_back({i,j});
                }
            }
        }

        return results;
        
    }
};

