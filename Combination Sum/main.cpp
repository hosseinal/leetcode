class Solution {
public:
    int sum_all(vector<int>& sum_arr) {
        int s = 0;
        for (int i = 0; i < sum_arr.size(); i++) {
            s += sum_arr[i];
        }
        return s;
    }

    int calculate_permutation(
        vector<int>& permutation,
        vector<int>& numbers,
        vector<vector<int>>& final_results,
        int target,
        int start
    ) {
        int s = sum_all(permutation);

        if (s == target) {
            final_results.push_back(permutation);
            return 1;
        }

        if (s > target) {
            return -1;
        }

        for (int i = start; i < numbers.size(); i++) {
            permutation.push_back(numbers[i]);

            int r = calculate_permutation(permutation, numbers, final_results, target, i);

            permutation.pop_back();

            if (r == -1) {
                break;
            }
        }

        return 1;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        vector<int> permutation;

        sort(nums.begin(), nums.end());

        calculate_permutation(permutation, nums, results, target, 0);

        return results;
    }
};
