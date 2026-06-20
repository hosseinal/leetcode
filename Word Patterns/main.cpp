class Solution {
public:
    bool wordPattern(string pattern, string s) {

        stringstream ss(s);
        string token = "";
        vector<string> words{};
        while(std::getline(ss,token,' ')){
            words.push_back(token);
        }

        if(words.size() != pattern.size()) return false;

        unordered_map<char,string> match{};

        unordered_map<string,char> match_rev{};

        for(int i = 0; i<pattern.size();i++){
            if(match.contains(pattern[i])){
                string pat =  match[pattern[i]];
                if(pat != words[i]) return false;
            }else if(match_rev.contains(words[i])){
                char c = match_rev[words[i]];
                if(c != pattern[i]) return false;
            }
            match[pattern[i]] = words[i];
            match_rev[words[i]] = pattern[i]; 
        }

        return true;
        
        
    }
};
