class Solution 
{
    public:
    
    int dfs(int i,int j,vector<vector<int> > &mat,vector<vector<int> > &dp,int par)
    {
        int r=mat.size(),c=mat[0].size();
        if(i<0 || j<0 || i>=r || j>=c || mat[i][j]==-2 || mat[i][j]<=par)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        //Left
        int left=dfs(i,j-1,mat,dp,mat[i][j]);
        //Right
        int right=dfs(i,j+1,mat,dp,mat[i][j]);
        //Up
        int up=dfs(i-1,j,mat,dp,mat[i][j]);
        //Down
        int down=dfs(i+1,j,mat,dp,mat[i][j]);
        dp[i][j]=max(left,max(right,max(up,down)))+1;
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int r=matrix.size();
        if(r==0)
        {
            return 0;
        }
        int c=matrix[0].size(),ans=0;
        vector<vector<int> > dp(r,vector<int> (c,-1));
        for (int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
            {
                ans=max(ans,dfs(i,j,matrix,dp,INT_MIN));
            }
        }
        return ans;
    }
};