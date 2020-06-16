//Good question uses memoisation

class Solution 
{
    public:

    void find(vector<int>& arr,int i,int j,vector<vector<long long int>>& dp)
    {
        if (i==j)
        {
            dp[i][j]=0;
        }
        if (j==i+1)
        {
            dp[i][j]=arr[i]*arr[j];
        }
        for (int k=i;k<j;k++)
        {
            int x=INT_MIN;
            for (int t=i;t<=k;t++)
            {
                x=max(x,arr[t]);
            }
            int y=INT_MIN;
            for (int t=k+1;t<=j;t++)
            {
                y=max(y,arr[t]);
            }
            if (dp[i][k]==2147483647)
            {
                find(arr,i,k,dp);
            }
            if (dp[k+1][j]==2147483647)
            {
                find(arr,k+1,j,dp);
            }
            dp[i][j]=min(dp[i][j],x*y+dp[i][k]+dp[k+1][j]);
        }
    }
    
    int mctFromLeafValues(vector<int>& arr) 
    {
        vector<vector<long long int> > dp;
        vector<long long int> temp;
        for (int i=0;i<arr.size();i++)
        {
            temp.push_back(2147483647);
        }
        for (int i=0;i<temp.size();i++)
        {
            dp.push_back(temp);
        }
        find(arr,0,arr.size()-1,dp);
        return dp[0][arr.size()-1];
    }
};