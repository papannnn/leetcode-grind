class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1;
        
        int l = 0;
        while (l < arr.size() - 1) {
            int r = l + 1;
            if (arr[l] == arr[r]) {
                l = r;
                continue;
            }

            bool checkBig = arr[r - 1] < arr[r];
            int curr = 1;
            while (r < arr.size()) {
                if (checkBig) {
                    if (arr[r - 1] < arr[r]) {
                        curr++;
                        r++;
                        checkBig = !checkBig;
                    } else {
                        break;
                    }
                } else {
                    if (arr[r - 1] > arr[r]) {
                        curr++;
                        r++;
                        checkBig = !checkBig;
                    } else {
                        break;
                    }
                }
            }

            l = r - 1;
            if (curr != 1) {
                res = max(res, curr);
            }
        }
        return res;
    }
};