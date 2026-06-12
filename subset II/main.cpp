class Solution {
public:


    bool exist(vector<int>& visited,unordered_set<string> &exist){

        string s = "";

        for(int x:visited){
            s += to_string(x) + "-";
        }

        if (exist.contains(s)){
            return true;
        }

        exist.insert(s);
        return false;

    }

    vector<int> newNums(vector<int> nums){
        vector<int> new_nums{};
        unordered_set<int> e{};
        for(int x:nums){
            if (!e.contains(x)) new_nums.push_back(x);
        }

        return new_nums;
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        
        sort(nums.begin(), nums.end());
        size_t size = nums.size();
        unordered_set<string> e{};
        vector<vector<int>> result {{}};
        for (int i = 0; i < size; i++ ){
            
            int result_size = result.size();
            for(int j = 0; j < result_size ; j++){
                vector<int> c = result[j];
                c.push_back(nums[i]);

                if (exist(c,e)) continue;

                result.push_back(c);
            }

        }
        return result;
        
    }
};



