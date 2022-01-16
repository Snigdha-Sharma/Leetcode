class Solution 
{
    public:
    int minDistance(string word1, string word2) 
    {
        //This question is simply finding the longest common subsequence of both strings. After deletion, LCSub of both strings will be the resultant common string. 
        //So no of deletions here will be total characters-two times the number of common subsequence characters
        int N=word1.size(),M=word2.size();
        vector<vector<int> > dp(N+1,vector<int> (M+1,0));
        for (int i=1;i<=N;i++)
        {
            for (int j=1;j<=M;j++)
            {
                if (word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return N+M-2*dp[N][M];
    }
};