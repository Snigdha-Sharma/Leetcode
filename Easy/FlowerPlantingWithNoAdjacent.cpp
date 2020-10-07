class Solution 
{
    public:
    
    void showAdjList(vector<vector<int> > &A)
    {
        for (int i=1;i<A.size();i++)
        {
            cout<<i<<":"<<endl;
            for (int j=0;j<A[i].size();j++)
            {
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) 
    {
        vector<int> colors(N+1,-1);
        vector<int> status(N+1,0);
        
        vector<vector<int> > adj(N+1);
        for (int i=0;i<paths.size();i++)
        {
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        //showAdjList(adj);
        for (int i=1;i<=N;i++)
        {
            vector<int> avail(5,1);
            for (int j=0;j<adj[i].size();j++)
            {
                if (status[adj[i][j]]==1)
                {
                    avail[colors[adj[i][j]]]=0;
                }
            }
            for (int j=1;j<=4;j++)
            {
                if (avail[j]==1)
                {
                    colors[i]=j;
                    status[i]=1;
                    break;
                }
            }
        }
        vector<int> ans;
        for (int i=1;i<=N;i++)
        {
            ans.push_back(colors[i]);
        }
        return ans;
    }
};