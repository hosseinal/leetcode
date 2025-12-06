class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        for (int i = 0; i < nums.size(); i++){
            umap[nums[i]] = i;
        }

        for (int i = 0 ; nums.size(); i++){
            int diff = target - nums[i];
            if (umap.count(diff) && umap[diff] != i){
                return {i, umap[diff]};
            }
        }
    
        return {0, 0};
    }
};

