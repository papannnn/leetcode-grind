struct Project {
    int profit;
    int capital;
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        auto comparatorCapital = [] (const Project& a, const Project& b) {
            return a.capital > b.capital;
        };

        priority_queue<Project, vector<Project>, decltype(comparatorCapital)> minHeapCapital;
        for (int i = 0 ; i < profits.size(); i++) {
            minHeapCapital.push({profits[i], capital[i]});
        }

        auto profitComparator = [] (const Project& a, const Project& b) {
            return a.profit < b.profit;
        };

        int res = w;
        priority_queue<Project, vector<Project>, decltype(profitComparator)> maxHeapProfit;
        while (k) {
            while (minHeapCapital.size() && w >= minHeapCapital.top().capital) {
                maxHeapProfit.push(minHeapCapital.top());
                minHeapCapital.pop();
            }

            k--;
            if (maxHeapProfit.size() && w >= maxHeapProfit.top().capital) {
                w += maxHeapProfit.top().profit;
                res += maxHeapProfit.top().profit;
                maxHeapProfit.pop();
            }
        }

        return res;
    }
};