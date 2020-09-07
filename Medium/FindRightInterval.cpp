class Solution 
{
    public:
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) 
    {
        map<int,int> m;
        for (int i=0;i<intervals.size();i++)
        {
            m[intervals[i][0]]=i;
        }
        vector<int> ans(intervals.size(),0);
        for (int i=0;i<intervals.size();i++)
        {
            auto it=m.lower_bound(intervals[i][1]);
            if (it==m.end())
            {
                ans[i]=-1;
            }
            else
            {
                ans[i]=it->second;
            }
        }
        return ans;
    }
};