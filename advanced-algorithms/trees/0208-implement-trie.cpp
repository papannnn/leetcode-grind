struct Node {
    Node* alphabet[26];
    bool terminal;

    Node() {
        terminal = false;
        for (int i = 0 ; i < 26; i++) {
            alphabet[i] = nullptr;
        }
    }
};

class PrefixTree {
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        int idx = 0;
        while (idx < word.size()) {
            char c = word[idx];
            if (curr->alphabet[c - 'a'] == nullptr) {
                curr->alphabet[c - 'a'] = new Node();
            }

            curr = curr->alphabet[c - 'a'];
            idx++;
        }

        curr->terminal = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        int idx = 0;
        while (curr && idx < word.size()) {
            char c = word[idx];

            curr = curr->alphabet[c - 'a'];
            idx++;
        }
        // cout << endl;

        if (curr) {
            return curr->terminal;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        int idx = 0;
        while (curr && idx < prefix.size()) {
            char c = prefix[idx];

            curr = curr->alphabet[c - 'a'];
            idx++;
        }

        return curr;
    }

private:
    Node* root;
};
