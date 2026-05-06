class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 1){
            return nums[0];
        }
        
        vector<int> cost(nums.size(),0);
        cost[0]=nums[0];
        cost[1] = max(nums[0],nums[1]);
        for (int i = 2 ; i < nums.size()-1; i+=1){
            cost[i] = max(cost[i-1],cost[i-2] + nums[i]);
        }



        vector<int> cost2(nums.size(),0);
        cost2[1]= nums[1];
        cost2[2] = max(nums[1],nums[2]);
        for (int i = 3 ; i < nums.size(); i+=1){
            cost2[i] = max(cost2[i-1],cost2[i-2] + nums[i]);
        }

        return max(cost2[cost2.size()-1], cost[cost.size()-2]);
    }
};

