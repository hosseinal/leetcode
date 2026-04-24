class WordDictionary {
public:
    struct searchTree {
        searchTree* children[26];
        bool wordEsists;
        searchTree() : wordEsists(false) {
            for (int i = 0; i < 26; ++i) children[i] = nullptr;
        }
    };


    searchTree* root;

    WordDictionary() {
        root = new searchTree();
    }
    
    void addWord(string word) {
        searchTree* currNode = root;
        for (int i = 0 ; i < word.size(); i++){
            int idx = word[i] - 'a';
            if (currNode->children[idx] == nullptr){
                currNode->children[idx] = new searchTree();
            }
            currNode = currNode->children[idx];
        }
        currNode->wordEsists = true;
    }
    
    bool dfs(string& word, int pos, searchTree* node) {
        if (node == nullptr){
            return false;
        }

        if (pos == word.size()) {
            return node->wordEsists;
        }

        if (word[pos] == '.'){
            for (int i = 0; i < 26;i++){
                if (node->children[i] != nullptr){
                    if(dfs(word,pos+1,node->children[i])){
                        return true;
                    }
                }
            }
            return false;
        }

        else {
            int idx = word[pos] - 'a';
            return dfs(word, pos + 1, node->children[idx]);
        }
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

