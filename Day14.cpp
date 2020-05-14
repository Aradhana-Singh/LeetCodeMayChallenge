//Implement Trie (Prefix Tree)
#define charSize 128
class Trie {
public:
        Trie* node[charSize];
        bool isLastNode;
    Trie() {
        this->isLastNode = false;
        for(int i = 0; i<charSize; i++){
            this->node[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur = this;
        for(int i = 0; i<word.size(); i++){
            if(cur->node[word[i]] == nullptr){
                cur->node[word[i]] = new Trie();
            }
            cur = cur->node[word[i]];
        }
        cur->isLastNode = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(this == nullptr) return false;
        Trie* cur = this;
        for(int i = 0 ; i<word.size(); i++){
            cur = cur->node[word[i]];
            if(cur == nullptr) return false;
        }
        return cur->isLastNode;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(this == nullptr) return false;
        Trie* cur = this;
        for(int i = 0 ; i<prefix.size(); i++){
            cur = cur->node[prefix[i]];
            if(cur == nullptr) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */