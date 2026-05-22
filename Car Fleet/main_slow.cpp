class Solution {
public:

    bool twoCarsCanReach(int backCarSpeed, 
                         int backCarPosition,
                         int frontCarSpeed,
                         int frontCarPosition,
                         int target) {
        
        if (backCarSpeed <= frontCarSpeed) {
            return false;
        }

        double moments = (double)(target - frontCarPosition) / frontCarSpeed;

        if ((frontCarPosition - backCarPosition) > 
            ((backCarSpeed - frontCarSpeed) * moments)) {
            return false;
        }

        return true;
    }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> paired(position.size());

        for (int i = 0; i < position.size(); i++) {
            paired[i] = {position[i], speed[i]};
        }

        sort(paired.begin(), paired.end());

        stack<pair<int, int>> s;

        for (int i = 0; i < paired.size(); i++) {
            int frontCarPosition = paired[i].first;
            int frontCarSpeed = paired[i].second;

            while (!s.empty()) {
                auto backCar = s.top();

                int backCarPosition = backCar.first;
                int backCarSpeed = backCar.second;

                bool reach = twoCarsCanReach(
                    backCarSpeed,
                    backCarPosition,
                    frontCarSpeed,
                    frontCarPosition,
                    target
                );

                if (reach) {
                    s.pop();
                } else {
                    break;
                }
            }

            s.push({frontCarPosition, frontCarSpeed});
        }

        return s.size();
    }
};
