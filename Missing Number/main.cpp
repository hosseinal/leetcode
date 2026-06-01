class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int size = nums.size();
        int sum = 0;
        for(auto v:nums){
            sum += nums[i];
        }

        int sum_all= (size * (size+1))/2;

        return sum_all - sum;



        // OR

        int size = nums.size();
        int sum_all= (size * (size+1))/2;
        for(auto v:nums){
            sum_all -= v;
        }
        return sum_all;
    }
};

