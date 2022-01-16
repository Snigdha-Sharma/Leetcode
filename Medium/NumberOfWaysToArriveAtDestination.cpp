class Solution 
{
    public:
    
    long long int mod=1000000007;
    
    
    void noOfWays(long long int n, vector<vector<long long int> > &parent,vector<long long int> &visits)
    {
        if (parent[n].size()==0)
        {
            visits[n]=1;
            return;
        }
        long long int x=0;
        for (long long int i=0;i<parent[n].size();i++)
        {
            if (visits[parent[n][i]]==-1)
            {
                noOfWays(parent[n][i],parent,visits);
            }
            x=(x+visits[parent[n][i]]%mod)%mod;
        }
        visits[n]=x;
    }
    
    int countPaths(int n, vector<vector<int>>& roads) 
    {

        //Making the adjacency list from given edges
        vector<vector<pair<long long int,long long int> > > adj_list(n,vector<pair<long long int, long long int> > ());
        for (long long int i=0;i<roads.size();i++)
        {
            adj_list[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj_list[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        //Dijkstra's Algorithm to get all shortest paths from 0 to n-1
        vector<long long int> dist(n,LONG_MAX);
        vector<vector<long long int> > parent(n,vector<long long int>());//Be careful since we can have multiple shortest paths in this problem, we can have multiple 
        //parent nodes for a given node so take a vector for it
        dist[0]=0;
        vector<long long int> visited(n,0);
        for (long long int i=0;i<n-1;i++)
        {
            long long int node=-1,minDist=LONG_MAX;

            //Select min distance unprocessed vertex
            for (long long int j=0;j<n;j++)
            {
                if (visited[j]==0)
                {
                    if (dist[j]<=minDist)
                    {
                        minDist=dist[j];
                        node=j;
                    }
                }
            }

            //Add this node to the processed nodes set
            visited[node]=1;

            //Visit all connected nodes from this node and update their distances if required
            for (long long int j=0;j<adj_list[node].size();j++)
            {
                long long int neighbour=adj_list[node][j].first;
                if (visited[neighbour]==0)
                {
                    if (dist[neighbour]==LONG_MAX || dist[node]+adj_list[node][j].second<dist[neighbour])
                    {
                        dist[neighbour]=dist[node]+adj_list[node][j].second;
                        parent[neighbour].clear();
                        parent[neighbour].push_back(node);
                    } 
                    else if (dist[node]+adj_list[node][j].second==dist[neighbour])
                    {
                        parent[neighbour].push_back(node);
                    }
                }
            }

        }

        //Simple DP arroach to get total no of ways 
        vector<long long int> visits(n,-1);
        noOfWays(n-1,parent,visits);
        
        return visits[n-1]%mod;
    }
};