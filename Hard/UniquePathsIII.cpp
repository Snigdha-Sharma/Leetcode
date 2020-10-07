//Very good question uses backtracking

class Solution 
{
    public:
    
    int totalPaths=0;
    
    void dfs(vector<vector<int> > &grid,int i,int j,int totalZero)
    {
        if (i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1 || grid[i][j]==-1 || (grid[i][j]==2 && totalZero!=0) || grid[i][j]==99)
        {
            return;
        }
        if (grid[i][j]==2 && totalZero==0)
        {
            totalPaths++;
        }
        if (grid[i][j]==0)
        {
            totalZero--;
        }
        int temp=grid[i][j];
        grid[i][j]=99;
        dfs(grid,i+1,j,totalZero);
        dfs(grid,i-1,j,totalZero);
        dfs(grid,i,j+1,totalZero);
        dfs(grid,i,j-1,totalZero);
        grid[i][j]=temp;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int count0=0;
        int n=grid.size(),m=grid[0].size();
        
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (grid[i][j]==0)
                {
                    count0++;
                }
            }
        }
        //cout<<count0<<endl;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (grid[i][j]==1)
                {
                    //cout<<"I="<<i<<",J="<<j<<endl;
                    dfs(grid,i,j,count0);
                    break;
                }
            }
        }
        
        return totalPaths;
    }
};