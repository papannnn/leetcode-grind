class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> idxChar(26);
        for (int i = 0; i < idxChar.size(); i++) {
            idxChar[i] = -1;
        }

        for (int i = 0 ; i < order.size(); i++) {
            idxChar[order[i] - 'a'] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string &firstWord = words[i];
            string &secondWord = words[i + 1];

            bool same = true;
            for (int j = 0; j < min(firstWord.size(), secondWord.size()); j++) {
                int firstIdx = idxChar[firstWord[j] - 'a'];
                int secondIdx = idxChar[secondWord[j] - 'a'];
                same &= firstIdx == secondIdx;
                if (firstIdx > secondIdx) {
                    return false;
                }

                if (firstIdx < secondIdx) {
                    break;
                }
            }
            
            if (same && firstWord.size() > secondWord.size()) {
                return false;
            }
        }
        return true;
    }
};