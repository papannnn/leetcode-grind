class Solution {
public:
    bool traverse(char curr) {
        if (visited.find(curr) != visited.end()) {
            return !visited[curr];
        }

        visited[curr] = true;
        for (char next : adjList[curr]) {
            if (!traverse(next)) {
                return false;
            }
        }
        visited[curr] = false;
        result.push_back(curr);
        return true;
    }

    string foreignDictionary(vector<string>& words) {
        for (int i = 0 ; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];

            int minSize = min(word1.size(), word2.size());
            if (word1.size() > word2.size() && word1.substr(0, minSize) == word2.substr(0, minSize)) {
                return "";
            }

            for (int j = 0; j < minSize; j++) {
                if (word1[j] != word2[j]) {
                    adjList[word1[j]].insert(word2[j]);
                    break;
                }
            }
        }

        for (const auto& m : adjList) {
            if (!traverse(m.first)) {
                return "";
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }

private:
    unordered_map<char, unordered_set<char>> adjList;
    unordered_map<char, bool> visited;
    string result;
};
