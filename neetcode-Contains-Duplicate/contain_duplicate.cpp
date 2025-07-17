class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> exists;
        for (int i = 0; i < nums.size(); i++){
            bool e = exists.find(nums[i]) != exists.end();
            if (e){
                return true;
            }else{
                exists[nums[i]] = 1;
            }
        }

        return false;
        
    }
};
