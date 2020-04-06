class Solution 
{
    public:
    int findLucky(vector<int>& arr) 
    {
        vector<int> freq;
        for (int i=1;i<=500;i++)
        {
            freq.push_back(0);
        }
        for (int i=0;i<arr.size();i++)
        {
            freq[arr[i]]++;
        }
        int ans=-1;
        for (int i=1;i<freq.size();i++)
        {
            if (i==freq[i])
            {
                ans=max(ans,i);
            }
        }
        return ans;
    }
};