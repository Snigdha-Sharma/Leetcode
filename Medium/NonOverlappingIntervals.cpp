class Solution 
{
    public:
    
    static bool compare(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if (intervals.size()==0)
        {
            return 0;
        }
        sort(intervals.begin(),intervals.end(),compare);
        int ans=-1,lastIntervalEnd=intervals[0][1];
        for (int i=0;i<intervals.size();i++)
        {
            if (intervals[i][0]<lastIntervalEnd)
            {
                //cout<<intervals[i+1][0]<<" "<<intervals[i][1]<<endl;
                ans++;
            }
            else
            {
                lastIntervalEnd=intervals[i][1];
            }
        }
        return ans;
    }
};