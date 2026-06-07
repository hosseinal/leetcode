class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        std::sort(intervals.begin(),intervals.end());
        int pre = 0;
        int counter = 0;
        for(int i = 1 ; i < intervals.size(); i++){
            if (intervals[pre][1]>intervals[i][0]){
                //overlap
                counter+=1;
                if(intervals[pre][1]>intervals[i][1]){
                    pre=i;
                }
            }
            else{
                //nonoverlap
                pre = i;
            }
        }


        return counter;
        
    }
};

