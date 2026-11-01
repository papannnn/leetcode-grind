struct Car {
    int pos;
    int speed;
    double arriveTime;
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> arrCar;
        for (int i = 0 ; i < position.size(); i++) {
            double arriveTime = static_cast<double>(target - position[i]) / speed[i];
            arrCar.push_back({ position[i], speed[i], arriveTime });
        }

        auto comp = [] (const Car& a, const Car& b) {
            return a.pos > b.pos;
        };
        sort(arrCar.begin(), arrCar.end(), comp);

        vector<Car> stk;
        for (int i = 0 ; i < arrCar.size(); i++) {
            cout << arrCar[i].arriveTime << endl;
            while (!stk.empty() && stk.back().arriveTime >= arrCar[i].arriveTime) {
                arrCar[i].arriveTime = stk.back().arriveTime;
                stk.pop_back();
            }

            stk.push_back(arrCar[i]);
        }
        return stk.size();
    }
};
