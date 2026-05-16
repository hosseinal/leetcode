class Solution {
public:
    bool check(string& s, vector<string>& wordDict, int start, int end) {
        int size = end - start + 1;

        for (int x = 0; x < wordDict.size(); x++) {
            if (size == wordDict[x].size()) {
                bool c = true;

                for (int y = 0; y < size; y++) {
                    if (wordDict[x][y] != s[start + y]) {
                        c = false;
                        break;
                    }
                }

                if (c == true) {
                    return true;
                }
            }
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        int minLen = n;
        int maxLen = 0;

        for (int i = 0; i < wordDict.size(); i++) {
            int size = wordDict[i].size();

            if (size < minLen) {
                minLen = size;
            }

            if (size > maxLen) {
                maxLen = size;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int len = minLen; len <= maxLen; len++) {
                if (i - len >= 0 && dp[i - len] == true) {
                    if (check(s, wordDict, i - len, i - 1)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};
