class Solution {
public:
    void calculate_permutation(
        vector<int>& permutation,
        vector<int>& numbers,
        vector<bool>& choose,
        vector<vector<int>>& final_results
    ) {
        if (permutation.size() == numbers.size()) {
            final_results.push_back(permutation);
            return;
        }

        for (int i = 0; i < numbers.size(); i++) {
            if (!choose[i]) {
                permutation.push_back(numbers[i]);
                choose[i] = true;

                calculate_permutation(permutation, numbers, choose, final_results);

                permutation.pop_back();
                choose[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<bool> chosen(nums.size(), false);
        vector<int> permutation;

        calculate_permutation(permutation, nums, chosen, results);

        return results;
    }
};
