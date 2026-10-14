class TrieNode {
public: 
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        endOfWord = false;
    }

};
class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for(char c : word) {
            // index of node is char
            int i = c - 'a'; // cast char to idx
            if(curr->children[i] == nullptr) {
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
        }
        // after inserting chars, end word
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for (char c : word) {
            // go through tree matching chars until endOfWord
            int i = c - 'a';
            if(curr->children[i] == nullptr) { // not in trie
                return false;
            }
            curr = curr->children[i];
        }
        return curr->endOfWord; // if end of word is true, exact word match
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(char c : prefix) {
            int i = c - 'a';
            if(curr->children[i] == nullptr) {
                return false;
            }
            curr = curr->children[i];
        }
        return true; // don't care about end of word, just prefix match
    }
};
