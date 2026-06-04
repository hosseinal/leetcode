class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {


        // Slower Version
        int size = matrix.size();

        for(int i = 0 ; i < size/2 ; i++){
            for (int j = 0 ; j < size; j++){
                int temp = matrix[size-i-1][j];
                matrix[size-i - 1][j]=  matrix[i][j];
                matrix[i][j] = temp;
            }
        }

        for(int i = 0; i < size; i++){
            for (int j = i ; j < size; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }


        // Faster Version
        int n = matrix.size();

        for (int i = 0; i < n / 2; ++i) {
            std::swap(matrix[i], matrix[n - 1 - i]);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        
    }
};

