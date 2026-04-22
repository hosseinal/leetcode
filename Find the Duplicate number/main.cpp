class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int index = nums.size()-1;
        for (int i = 0 ; i < nums.size(); i++){
            int val = nums[i];
            
            if (val < 0) {
                val = -1 * val; 
            }

            if (nums[val-1] < 0){
                return val;
            }
            nums[val-1] = -1 * nums[val-1];
        }   
        return 0;
        
    }
};

