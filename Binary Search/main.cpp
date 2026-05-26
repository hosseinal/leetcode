class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int size = nums.size();

        int left_index = 0;
        int right_index = nums.size() -1;

        while(left_index <= right_index) {
            int middle = left_index + ((right_index - left_index) / 2);
            
            if (target < nums[middle]){
                right_index = middle -1;
            }else if (target > nums[middle]){
                left_index = middle + 1;
            }else{
                return middle;
            }

        }
        
        return -1;
    }
};

