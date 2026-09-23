class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> freqList{0, 0};
        for (const auto &s : students) {
            freqList[s]++;
        }
        int result = students.size();
        for (int i = 0 ; i < sandwiches.size(); i++) {
            if (freqList[sandwiches[i]]) {
                freqList[sandwiches[i]]--;
                result--;
            } else {
                break;
            }
        }
        return result;
    }
};