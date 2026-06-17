class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs[0].size();
        for (int i=0;i<size;i++){
             char ss = strs[0][i];
             for(int j=0;j<strs.size();j++){
                if (strs[j].size() < i) return strs[0].substr(0, i-1);
                if(ss != strs[j][i]) return strs[0].substr(0, i);;
             }
        }

        return strs[0];

    }
};
