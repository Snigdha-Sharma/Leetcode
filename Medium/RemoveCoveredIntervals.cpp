class Solution 
{
    public:
    
    bool static compare(vector<int> &v1,vector<int> &v2)
    {
        if (v1[0]!=v2[0])
        {
            return v1[0]<v2[0];
        }
        return v1[1]>v2[1];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        int sz=intervals.size();
        sort(intervals.begin(),intervals.end(),compare);
        int ans=1,s=intervals[0][0],e=intervals[0][1];
        for (int i=1;i<sz;i++)
        {
            if (intervals[i][0]>=s && intervals[i][1]<=e)
            {
                continue;
            }
            else
            {
                s=min(s,intervals[i][0]);
                e=max(e,intervals[i][1]);
                ans++;
            }
        }
        return ans;
    }
    
};