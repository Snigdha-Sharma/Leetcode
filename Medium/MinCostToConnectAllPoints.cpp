class Solution 
{
    public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        long long int n=points.size();
        //Make adjacency matrix from given points
        vector<vector<long long int> > adj_mat(n,vector<long long int> (n,0));
        
        for (long long int i=0;i<n;i++)
        {
            for (long long int j=0;j<n;j++)
            {
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj_mat[i][j]=dist;
                adj_mat[j][i]=dist;
            }
        }
        
        // for (int i=0;i<n;i++)
        // {
        //     for (int j=0;j<n;j++)
        //     {
        //         cout<<adj_mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        //Applying Prim's algorithm to find MST
        set<long long int> included;
        vector<long long int> parent(n,-1),weight(n,LLONG_MAX);
        weight[0]=0;
        for (long long int i=0;i<n-1;i++)
        {
            //Find min weight unprocessed node
            long long int node=-1,nodeWeight=LLONG_MAX;
            for (long long int j=0;j<n;j++)
            {
                if (included.find(j)==included.end() && weight[j]<nodeWeight)
                {
                    nodeWeight=weight[j];
                    node=j;
                }
            }
            
            //Add current node to processed nodes set
            included.insert(node);
            
            //Check for all connected nodes if they could have been connected with a smaller weight edge
            for (long long int j=0;j<n;j++)
            {
                if (node==j || included.find(j)!=included.end())
                    continue;
                if (weight[j]==LLONG_MAX || weight[j]>adj_mat[node][j])
                {
                    weight[j]=adj_mat[node][j];
                    parent[j]=node;
                }
            }
        }
        
        // for (long long int i=0;i<n;i++)
        // {
        //     cout<<parent[i]<<" ";
        // }
        // cout<<endl;
        // for (long long int i=0;i<n;i++)
        // {
        //     cout<<weight[i]<<" ";
        // }
        long long int ans=0;
        for (long long int i=1;i<n;i++)
        {
            ans+=adj_mat[i][parent[i]];
        }
        return ans;
    }
};