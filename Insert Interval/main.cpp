class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        int size = intervals.size();
        
        while (i < size && intervals[i][1] < newInterval[0]) {
            i++;
        }
        
        int j = i;
        while (j < size && intervals[j][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[j][0]);
            newInterval[1] = max(newInterval[1], intervals[j][1]);
            j++;
        }
        
    
        intervals.erase(intervals.begin() + i, intervals.begin() + j);
        intervals.insert(intervals.begin() + i, move(newInterval));
        
        return intervals;
    }
};

