class Solution 
{
    public:
    
    int helper(vector<vector<int> > &grid,int r1,int c1, int r2,vector<vector<vector<int> > > &dp)
    {
        if (r1>=grid.size() || r2>=grid.size() || c1>=grid[0].size() || r1+c1-r2>=grid[0].size() || grid[r1][c1]==-1 || grid[r2][r1+c1-r2]==-1)
        {
            return INT_MIN;
        }
        if (r1==grid.size()-1 && c1==grid[0].size()-1)
        {
            return grid[r1][c1];
        }
        if (dp[r1][c1][r2]!=-2)
        {
            return dp[r1][c1][r2];
        }
        int cherries=0;
        if (r1==r2 && c1==r1+c1-r2)
        {
            cherries=grid[r1][c1];
        }
        else
        {
            cherries=grid[r1][c1]+grid[r2][r1+c1-r2];
        }

        int downDown=helper(grid,r1+1,c1,r2+1,dp);
        int downRight=helper(grid,r1+1,c1,r2,dp);
        int rightDown=helper(grid,r1,c1+1,r2+1,dp);
        int rightRight=helper(grid,r1,c1+1,r2,dp);
        cherries+=max(max(downDown,downRight),max(rightRight,rightDown));
        dp[r1][c1][r2]=cherries;
        return cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int N=grid.size();
        vector<vector<vector<int> > > dp(N,vector<vector<int> > (N,vector<int> (N,-2)));
        return max(0,helper(grid,0,0,0,dp));
    }
};