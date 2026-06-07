class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        std::sort(intervals.begin(),intervals.end());
        int size = intervals.size();
        vector<vector<int>> result;

        int i {0};
        while(i<size){
            int p = intervals[i][1];
            
            int j {i+1};
            int start = intervals[i][0];
            int end = intervals[i][1];
            while(j<size){
                if ((p>=intervals[j][0] &&p<intervals[j][1]) || p>=intervals[j][1]){
                    if (p<intervals[j][1]){
                        end = intervals[j][1];
                        p = intervals[j][1];
                    }
                   
                    j++;
                }else{
                    break;
                }
            }
            
            result.push_back({start,end});
            i = j;

        }

        return result;

    }
};

