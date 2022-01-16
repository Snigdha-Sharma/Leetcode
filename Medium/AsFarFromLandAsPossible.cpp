class Solution 
{
    public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        //Multi source bfs starting from land. Calculate distance matrix of distance of nearest land cell from each water cell. Then max value from this matrix is the 
        //answer
        int N=grid.size(),M=grid[0].size();
        vector<vector<int> > dp(N,vector<int> (M,INT_MAX));
        queue<pair<int,int> > q;
        for (int i=0;i<N;i++)
        {
            for (int j=0;j<M;j++)
            {
                if (grid[i][j]==1)
                {
                    q.push({i,j});
                    grid[i][j]=-1;
                    dp[i][j]=0;
                }
            }
        }
        if (q.size()==0 || q.size()==N*M)
        {
            return -1;
        }
        vector<vector<int> > directions={{-1,0},{1,0},{0,1},{0,-1}};
        
        int depth=1;
        while(!q.empty())
        {
            int sz=q.size();
            for (int i=0;i<sz;i++)
            {
                pair<int,int> popped=q.front();
                q.pop();
                int x=popped.first,y=popped.second;
                for (int i=0;i<4;i++)
                {
                    int nx=x+directions[i][0],ny=y+directions[i][1];
                    if (nx>=0 && nx<N && ny>=0 && ny<M && grid[nx][ny]!=-1)
                    {
                        grid[nx][ny]=-1;
                        dp[nx][ny]=min(dp[nx][ny],depth);
                        q.push({nx,ny});
                    }
                }
            }
            depth++;
        }
        int ans=0;
        for (int i=0;i<N;i++)
        {
            for (int j=0;j<M;j++)
            {
                //cout<<dp[i][j]<<" ";
                ans=max(ans,dp[i][j]);
            }
            //cout<<endl;
        }
        return ans;
    }
};