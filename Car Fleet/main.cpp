class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> paired(position.size());

        for (int i = 0; i < position.size(); i++) {
            paired[i] = {position[i], speed[i]};
        }

        sort(paired.rbegin(), paired.rend());

        stack<double> s;

        for (int i = 0; i < paired.size(); i++) {
            int carPosition = paired[i].first;
            int carSpeed = paired[i].second;

            double time = (double)(target - carPosition) / carSpeed;
            if (!s.empty() && time <= s.top()) {
                continue;
            }

            s.push(time);
        }

        return s.size();
    }
};
