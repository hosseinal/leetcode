class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> existance;

        for (auto num : nums) {
            existance.insert(num);
        }

        int maxCounter = 0;

        for (auto num : existance) {

            if (!existance.contains(num - 1)) {
                int counter = 0;
                int val = num;

                while (existance.contains(val)) {
                    counter++;
                    val++;
                }

                maxCounter = max(maxCounter, counter);
            }
        }

        return maxCounter;
    }
};
