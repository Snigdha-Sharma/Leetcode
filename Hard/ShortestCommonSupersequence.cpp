class Solution 
{
    public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        //First find the longest common subsequence. Then shortest common supersequence is just obtained by filling all the extra letter between the common letters 
        //from both the strings.
        int N=str1.size(),M=str2.size();
        vector<vector<string> > dp(N+1,vector<string> (M+1,""));
        for (int i=1;i<=N;i++)
        {
            for (int j=1;j<=M;j++)
            {
                if (str1[i-1]==str2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+str1[i-1];
                }
                else
                {
                    if (dp[i-1][j].size()>dp[i][j-1].size())
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j]=dp[i][j-1];
                    }
                    
                }
            }
        }
        // for (int i=0;i<=N;i++)
        // {
        //     for (int j=0;j<=M;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        string common=dp[N][M],ans="";
        int s1=0,s2=0;
        for (int i=0;i<common.size();i++)
        {
            while(str1[s1]!=common[i])
            {
                ans=ans+str1[s1++];
              
            }
            
            while(str2[s2]!=common[i])
            {
                ans=ans+str2[s2++];
                
            }
            
            ans=ans+common[i];
            s1++;
            s2++;
        }
        ans=ans+str1.substr(s1,N)+str2.substr(s2,M);
        return ans;
    }
};