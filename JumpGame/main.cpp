class Solution {
public:
    bool canJump(vector<int>& nums) {

        int finalDest = nums.size() - 1;

        for (int i = nums.size()-2 ; i >= 0; i--){
            if (i + nums[i] >= finalDest){
                finalDest = i;
            }
        }
        
        if (finalDest == 0){
            return true;
        }


        return false;
    }
};

