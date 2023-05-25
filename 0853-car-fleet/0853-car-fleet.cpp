class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        if (position.size() == 1) return 1;
        
        map<int, int> cars;
        stack<int> stk;
        
        auto fleets = 0;
        
        for (auto i = 0; i < speed.size(); i++) {
            cars[position[i]] = speed[i];
        }
        
        // O(nlogn)
        sort(position.begin(), position.end());
        
        for (int i = position.size() - 1; i >= 0; i--) {
            auto currCar = position[i];
            
            if (stk.empty()) {
                stk.push(currCar);
            } else {
                // (target - carPos) / carSpeed
                auto nextCar = stk.top();
                
                float currCarTime = (target - currCar) / static_cast<float>(cars[currCar]);
                float nextCarTime = (target - nextCar) / static_cast<float>(cars[nextCar]);
                
                
                if (currCarTime > nextCarTime) {
                    stk.push(currCar);
                }
                
            }
        }
        
        // while (!stk.empty()) {
        //     cout << stk.top() << " ";
        //     stk.pop();
        // }
        // cout << "\n";
        
        return stk.size();
    }
};

