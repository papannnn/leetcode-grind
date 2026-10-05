class DisjointSet {
public:
    DisjointSet(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        while (x != parent[x]) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    bool join(int x, int y) {
        if (find(y) == find(x)) {
            return false;
        }

        parent[find(y)] = find(x);
        return false;
    } 

private:
    unordered_map<int, int> parent;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToAccount;
        DisjointSet ds(accounts.size());

        for (int i = 0 ; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                const string& email = accounts[i][j];
                if (emailToAccount.find(email) == emailToAccount.end()) {
                    emailToAccount[email] = i;
                } else {
                    ds.join(i, emailToAccount[email]);
                }
            }
        }

        map<int, vector<string>> emailGroup;
        for (auto &m : emailToAccount) {
            const string& email = m.first;
            int accountIdx = ds.find(m.second);

            emailGroup[accountIdx].push_back(email);
        }

        vector<vector<string>> res;
        for (auto &m : emailGroup) {
            vector<string> temp;
            int accountIdx = m.first;
            const vector<string>& emailVector = m.second;
            if (emailVector.size() == 0) {
                continue;
            }

            temp.push_back(accounts[accountIdx][0]);
            temp.insert(temp.end(), emailVector.begin(), emailVector.end());
            res.push_back(temp);
        }
        return res;
    }
};