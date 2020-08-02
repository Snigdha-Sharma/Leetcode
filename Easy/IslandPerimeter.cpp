class Solution 
{
    public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int ans=0;
        for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid[0].size();j++)
            {
                if (grid[i][j]==1)
                {
                    //Up
                    if (i==0 || grid[i-1][j]==0)
                    {
                        ans++;
                    }
                    //Down
                    if (i==grid.size()-1 || grid[i+1][j]==0)
                    {
                        ans++;
                    }
                    //Left
                    if (j==0 || grid[i][j-1]==0)
                    {
                        ans++;
                    }
                    //Right
                    if (j==grid[0].size()-1 || grid[i][j+1]==0)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};