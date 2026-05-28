class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> results(n+1,0);
        int offset = 1;
        for (int i = 1; i < n+1; i++){
            if(i == offset *2){
                offset = i;
            }
            results[i] = 1 + results[i - offset];
        }

        return results;
    }
};

