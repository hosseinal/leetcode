class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int counter = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            if(!nums[i]){
                nums.erase(nums.begin()+i);
                i--;
                counter++;
            }
        }

        nums.insert(nums.end(), counter, 0);        
    }
};
