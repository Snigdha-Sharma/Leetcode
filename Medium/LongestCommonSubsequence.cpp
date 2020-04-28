class Solution 
{
    public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        vector<vector<int> > dp;
        vector<int> temp;
        for (int i=0;i<=text2.size();i++)
        {
            temp.push_back(0);
        }
        for (int i=0;i<=text1.size();i++)
        {
            dp.push_back(temp);
        }
        
        for (int i=1;i<=text1.size();i++)
        {
            for (int j=1;j<=text2.size();j++)
            {
                if (text1[i-1]==text2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // for (int i=0;i<=text1.size();i++)
        // {
        //     for (int j=0;j<=text2.size();j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[text1.size()][text2.size()];
    }
};