class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> total;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                total.push_back(total[total.size() - 1] + total[total.size() - 2]);
            } else if (operations[i] == "D") {
                int val = total.back();
                total.push_back(val * 2);
            } else if (operations[i] == "C") {
                total.pop_back();
            } else { // Number
                int val = stoi(operations[i]);
                total.push_back(val);
            }
        }
        int sum = 0;
        for (int i = 0 ; i < total.size(); i++) {
            cout << total[i] << endl;
            sum += total[i];
        }
        return sum;
    }
};