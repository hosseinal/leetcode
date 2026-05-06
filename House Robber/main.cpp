class Solution {
public:
    int rob(vector<int>& nums) {
        
    vector<int> cost(nums.size(),0);
    cost[0]=nums[0];
    cost[1] = max(nums[0],nums[1]);
    for (int i = 2 ; i < cost.size(); i+=1){
        cost[i] = max(cost[i-1],cost[i-2] + nums[i]);
    }

    return cost[nums.size()-1];
    }
};

