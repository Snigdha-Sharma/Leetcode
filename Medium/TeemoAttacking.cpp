class Solution 
{
    public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) 
    {
        int sz=timeSeries.size();
        if (sz==0)
        {
            return 0;
        }
        int start=timeSeries[0],end=start+duration,ans=0;
        for (int i=1;i<sz;i++)
        {
            if (timeSeries[i]>end)
            {
                ans=ans+(end-start);
                start=timeSeries[i];
                end=start+duration;
            }
            else
            {
                end=timeSeries[i]+duration;
            }
        }
        ans=ans+(end-start);
        return ans;
    }
};