class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for (int i = 0; i < strs.size(); i++){
            s += strs[i] + "-";
        }

        return s;
    
    }

    vector<string> decode(string s) {
        vector<string> strings;
        string temp = "";
        for (int i = 0 ; i < s.size(); i++){
            if (s[i] == '-') {
                strings.push_back(temp);
                temp = "";
            }
            else{
                temp += s[i];
            }
        }

        if (!temp.empty()){
            strings.push_back(temp);
        }

        return strings;
    }
};

