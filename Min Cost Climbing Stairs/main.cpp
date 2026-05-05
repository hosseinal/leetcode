class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> dynamicCost(cost.size() + 2, 0 );

        for (int i = 0 ; i < cost.size(); i++){
            dynamicCost[i+2] = min (dynamicCost[i],dynamicCost[i+1]) + cost[i];
        }


        int cSize = dynamicCost.size();

        int result = min(dynamicCost[cSize - 1], dynamicCost[cSize-2]);

        return result;        
    }
};

