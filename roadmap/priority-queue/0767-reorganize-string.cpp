struct Data {
    char c;
    int cnt;
};

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> arr(26);
        for (int i = 0 ; i < s.size(); i++) {
            arr[s[i] - 'a']++;
        }

        auto comp = [] (const Data& a, const Data& b) {
            return a.cnt < b.cnt;
        };
        priority_queue<Data, vector<Data>, decltype(comp)> q;
        for (char i = 0; i < arr.size(); i++) {
            if (arr[i] >= (s.size() + 1) / 2 + 1) {
                return "";
            }
            
            char c = i + 'a';
            if (arr[i] > 0) {
                q.push({c, arr[i]});
            }
        }

        string res = "";
        vector<Data> temp;
        temp.push_back({'Z', 0});
        while (!q.empty() && !temp.empty()) {
            if (q.empty()) {
                Data t = temp.back();
                temp.pop_back();
                if (t.cnt) {
                    q.push(t);
                }
                continue;
            }

            Data curr = q.top();
            q.pop();
            if (curr.cnt == 0) {
                continue;
            }
            curr.cnt--;
            res += curr.c;

            Data t = temp.back();
            temp.pop_back();
            if (t.cnt) {
                q.push(t);
            }

            temp.push_back(curr);
        }

        return res;
    }
};