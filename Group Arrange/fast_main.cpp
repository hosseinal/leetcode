class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<vector<int>, vector<string>> mapstr;

        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];

            vector<int> wordcounter(26, 0);

            for (char e : s) {
                wordcounter[e - 'a']++;
            }

            mapstr[wordcounter].push_back(s);
        }

        vector<vector<string>> results;

        for (auto& [key, lst] : mapstr) {
            results.push_back(lst);
        }

        return results;
    }
};
