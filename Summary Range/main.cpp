class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        std::vector<std::string> results{};
        if(nums.size() == 0){
            return results;
        }

        int start = nums[0];
        int end = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[i-1] + 1){
                end = nums[i-1];
                if (end == start){
                  results.push_back(to_string(start));
                }else{
                    string r = to_string(start)+"->"+to_string(end);
                    results.push_back(r);

                }                
                start = nums[i];
            }
        }
        end = nums[nums.size() - 1];
        if(start == end || start > end){
            results.push_back(to_string(start));
        }else{
            string r = to_string(start)+"->"+to_string(end);
            results.push_back(r);
        }

        return results;
    }
};
