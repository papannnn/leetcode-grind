struct Node {
    Node* alphabet[26];
    bool endOfWord{false};

    Node() {
        for (int i = 0; i < 26; i++) {
            alphabet[i] = nullptr;
        }
    }
};

class Trie {
public:

    Trie() {
        root = new Node();
    }

    void insert(string& word) {
        Node* curr = root;
        for (int i = 0 ; i < word.size(); i++) {
            char c = word[i];
            if (curr->alphabet[c - 'a'] == nullptr) {
                curr->alphabet[c - 'a'] = new Node();
            }

            curr = curr->alphabet[c - 'a'];
        }
        curr->endOfWord = true;
    }

    bool check(string &word) {
        Node* curr = root;
        for (int i = 0 ; i < word.size(); i++) {
            char c = word[i];
            if (curr->alphabet[c - 'a'] == nullptr) {
                return false;
            }

            curr = curr->alphabet[c - 'a'];
        }

        return curr->endOfWord;
    }

    bool hasPrefix(string &prefix) {
        Node* curr = root;
        for (int i = 0 ; i < prefix.size(); i++) {
            char c = prefix[i];
            if (curr->alphabet[c - 'a'] == nullptr) {
                return false;
            }
            
            curr = curr->alphabet[c - 'a'];
        }

        return true;
    }

    void remove(string& word) {
        Node* curr = root;
        for (char c : word) {
            curr = curr->alphabet[c - 'a'];
        }
        curr->endOfWord = false;
    }

private:
    Node* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        
        for (int i = 0 ; i < words.size(); i++) {
            trie.insert(words[i]);
        }

        for (int i = 0 ; i < board.size(); i++) {
            for (int j = 0 ; j < board[i].size(); j++) {
                traverse(i, j, board, "");
            }
        }

        return res;
    }

private:
    Trie trie;
    vector<vector<bool>> visited;
    vector<string> res;

    bool traverse(int y, int x, vector<vector<char>>& board, string str) {
        if (x < 0 || y < 0) {
            return false;
        }

        if (x == board[0].size() || y == board.size()) {
            return false;
        }

        if (visited[y][x]) {
            return false;
        }

        str += board[y][x];
        
        if (!trie.hasPrefix(str)) {
            return false;
        }

        if (trie.check(str)) {
            res.push_back(str);
            trie.remove(str);
        }

        visited[y][x] = true;
        bool result = false;
        result |= traverse(y + 1, x, board, str);
        result |= traverse(y, x + 1, board, str);
        result |= traverse(y - 1, x, board, str);
        result |= traverse(y, x - 1, board, str);

        visited[y][x] = false;
        return result;
    }
};
