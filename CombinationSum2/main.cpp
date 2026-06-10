class Solution {
public:
    int sum_all(vector<int>& sum_arr) {
        int s = 0;
        for (int i = 0; i < sum_arr.size(); i++) {
            s += sum_arr[i];
        }
        return s;
    }

    void calculate_permutation(
        vector<int>& permutation,
        vector<int>& numbers,
        vector<vector<int>>& final_results,
        int target,
        int start
    ) {
        int s = sum_all(permutation);

        if (s == target) {
            final_results.push_back(permutation);
            return;
        }

        if (s > target) {
            return;
        }

        for (int i = start; i < numbers.size(); i++) {
            // skip duplicates at the same recursion level
            if (i > start && numbers[i] == numbers[i - 1]) {
                continue;
            }

            permutation.push_back(numbers[i]);

            // i + 1 because each number can be used once
            calculate_permutation(permutation, numbers, final_results, target, i + 1);

            permutation.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> permutation;

        sort(candidates.begin(), candidates.end());

        calculate_permutation(permutation, candidates, results, target, 0);

        return results;
    }
};
