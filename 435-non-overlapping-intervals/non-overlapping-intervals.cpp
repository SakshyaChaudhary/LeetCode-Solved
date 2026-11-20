class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        sort(intervals.begin(),intervals.end(),compare);
        int count=0;
        int endTime=INT_MIN;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=endTime){
                count++;
                endTime=intervals[i][1];
            }
        }
        return intervals.size()-count;        
    }
    static bool compare(vector<int> v1,vector<int>v2){
        return v1[1]<v2[1];
    }
};