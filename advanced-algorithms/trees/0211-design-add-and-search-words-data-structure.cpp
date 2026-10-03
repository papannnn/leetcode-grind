struct Node {
    Node* alphabet[26];
    bool endOfWord{false};

    Node() {
        for (int i = 0 ; i < 26; i++) {
            alphabet[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for (int i = 0 ; i < word.size(); i++) {
            if (curr->alphabet[word[i] - 'a'] == nullptr) {
                curr->alphabet[word[i] - 'a'] = new Node();
            }
            curr = curr->alphabet[word[i] - 'a'];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return search(root, 0, word);
    }

private:
    Node* root;

    bool search(Node* curr, int idx, const string& word) {
        if (curr == nullptr) {
            return false;
        }

        if (idx == word.size()) {
            return curr->endOfWord;
        }

        char c = word[idx];
        idx++;
        if (c == '.') {
            bool res = false;
            for (int i = 0 ; i < 26; i++) {
                res |= search(curr->alphabet[i], idx, word);
            }
            return res;
        } 
        
        return search(curr->alphabet[c - 'a'], idx, word);
    }
};
