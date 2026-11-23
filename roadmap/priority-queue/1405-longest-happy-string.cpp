struct Data {
    char c;
    int cnt;
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        auto comp = [] (const Data& a, const Data& b) {
            return a.cnt < b.cnt;
        };
        
        priority_queue<Data, vector<Data>, decltype(comp)> q;
        if (a) q.push({'a', a});
        if (b) q.push({'b', b});
        if (c) q.push({'c', c});

        vector<Data> temp;
        char prevChar = 'd';
        int prevCnt = 0;
        int prevStreak = 0;
        while (!q.empty()) {
            Data d = q.top();
            q.pop();
            if (d.cnt == 0) {
                continue;
            } 

            d.cnt--;
            res += d.c;
            
            if (d.c != prevChar) {
                prevStreak = 0;
                if (prevCnt > 0) {
                    q.push({prevChar, prevCnt});
                }
                prevChar = d.c;
                prevCnt = 0;
            }

            prevStreak++;
            if (prevStreak < 2) {
                q.push({d.c, d.cnt});
            } else {
                prevCnt = d.cnt;
            }
        }

        return res;
    }
};