class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mapstr;

        for (int i = 0; i < strs.size(); i++) {
            string s=strs[i];
            vector<int>wordcounter(26,0);
            for(char e:s){
                wordcounter[e-'a']++;
            }

            string key = "";
            for(int j = 0 ; j<26; j+=1){
                key+="/"+to_string(wordcounter[j]);
            }

            mapstr[key].push_back(s);
        }

        vector<vector<string>> results;

        for (auto [it,lst] : mapstr) {
            
            results.push_back(lst);
        }

        return results;
    }
};
