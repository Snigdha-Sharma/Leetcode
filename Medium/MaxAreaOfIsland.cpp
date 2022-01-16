class Solution 
{
    public:
    
    //Run dfs on each landmass that you find, compare the area and return the result
    int getAreaViaDFS(vector<vector<int>>& grid, int x, int y)
    {
        int area=1,N=grid.size(),M=grid[0].size();
        stack<pair<int,int> > st;
        st.push({x,y});
        vector<vector<int> > directions={{-1,0},{1,0},{0,1},{0,-1}};
        while(!st.empty())
        {
            pair<int,int> popped=st.top();
            st.pop();
            int x=popped.first,y=popped.second;
            //cout<<x<<" "<<y<<endl;
            
            grid[x][y]=-1;
            for (int i=0;i<4;i++)
            {
                int nx=x+directions[i][0],ny=y+directions[i][1];
                if (nx>=0 && nx<N && ny>=0 && ny<M && grid[nx][ny]==1)
                {
                    grid[nx][ny]=-1;
                    area++;
                    st.push({nx,ny});
                }
            }
        }
        //cout<<area<<" ";
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int N=grid.size(),M=grid[0].size(),ans=0;
        for (int i=0;i<N;i++)
        {
            for (int j=0;j<M;j++)
            {
                if (grid[i][j]==1)
                {
                    ans=max(ans,getAreaViaDFS(grid,i,j));
                }
            }
        }
        return ans;
    }
};