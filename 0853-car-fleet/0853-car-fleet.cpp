class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        // If just 1 car, then only 1 fleet
        if (position.size() == 1) return 1;
        
        
        map<int, int> cars;
        stack<int> stk;
        
        // Populate map with respective position and speed of each car        
        for (auto i = 0; i < speed.size(); i++) {
            cars[position[i]] = speed[i];
        }
        
        // O(nlogn)
        sort(position.begin(), position.end());
        
        // Iterate through cars backwards
        for (int i = position.size() - 1; i >= 0; i--) {
            auto currCar = position[i];
            
            // If stack empty, push car to stack
            if (stk.empty()) {
                stk.push(currCar);
            } else {
                // Otherwise compare the time it will take for current car and car in stack to reach destination
                // Formula: (target - carPos) / carSpeed
                
                // Get the car in stack
                auto nextCar = stk.top();
                
                // Calculate the time taken
                float currCarTime = (target - currCar) / static_cast<float>(cars[currCar]);
                float nextCarTime = (target - nextCar) / static_cast<float>(cars[nextCar]);
                
                
                // If the currentCar takes longer then the car in stack, that means they WILL NEVER intersect
                // and hence we push the car into the stack
                
                // Each car in the stack represents a fleet.
                if (currCarTime > nextCarTime) {
                    stk.push(currCar);
                }
                
                // If the currentCar takes less or equal time then the car in stack, that means they WILL intersect
                // In this case we don't need to push anything into the stack, as the car in the stack will represent 
                // that particular fleet. 
                
            }
        }
        
        // Each car in the stack represents a fleet
        return stk.size();
    }
};

