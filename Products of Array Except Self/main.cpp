class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int zero_counter = 0;
        int multiplication_result=1;
        int n = nums.size();
        for( int i = 0 ; i < n; i++){
            if (nums[i] == 0){
                zero_counter++;
            }else{
                multiplication_result = multiplication_result * nums[i];
            }
        }

        if (zero_counter > 1){
            vector<int> result(n, 0);
            return result;
        }
        
        if ( zero_counter == 1 ){
            vector<int> results(n, 0);
            for( int i = 0 ; i < nums.size(); i++){
                if (nums[i] == 0){
                results[i] = multiplication_result;
                }
            }
            return results;
        }


        vector<int> results(n, 0);
        for( int i = 0 ; i < nums.size(); i++){
            results[i] = multiplication_result/nums[i];
            
        }
        return results;

    }
};

