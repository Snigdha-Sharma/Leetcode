//The problem cant be solved by being greedy as when sorting the strings according to their lengths to take most of them, it may be possible that the 0's and 1's
//are distributed among many larger length strings. We basically allow each string that has zeros >= i and ones >=j to consider being part of our answer set. This problem
// is then solved by a dp

class Solution 
{
    public:
    
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector<vector<int> > dp(m+1,vector<int> (n+1,0));
        for(int c=0;c<strs.size();c++)
        {
            int count0=count(strs[c].begin(),strs[c].end(),'0'),count1=strs[c].size()-count0;
            for(int i=m;i>=count0;i--)
            {
                for(int j=n;j>=count1;j--)
                {
                    dp[i][j]=max(dp[i][j],dp[i-count0][j-count1]+1);
                }
            }
        }
        return dp[m][n];
    }
};