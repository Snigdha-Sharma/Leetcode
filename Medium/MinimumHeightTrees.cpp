class Solution 
{
    public:

    // Brute force solution here will be to consider each node as root of the tree and then calculate the maximum depth of N children tree. Then find the minimum value 
    //nodes from this. This would require that for each node when it is considered as tree we go through all rest nodes. Time Complexity: O(N*N)

    //For optimal solution we can see that the answer will be the centroid/ centroids of this graph. i.e. nodes that are close to all leaf nodes. So answer can only be 
    //2 nodes or 1 node. This solution finds the centroid of the given acyclic graph
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        vector<int> ans;
        if (n==1)
        {
            ans.push_back(0);
            return ans;
        }
        if (n==2)
        {
            ans.push_back(0);
            ans.push_back(1);
            return ans;
        }
        vector<unordered_set<int> > adj_list(n,unordered_set<int> ());
        for (int i=0;i<edges.size();i++)
        {
            adj_list[edges[i][0]].insert(edges[i][1]);
            adj_list[edges[i][1]].insert(edges[i][0]);
        }
        queue<int> q;
        for (int i=0;i<n;i++)
        {
            if (adj_list[i].size()==1)
            {
                q.push(i);
            }
        }
        int nodesLeft=n;
        while(nodesLeft>2)
        {
            int sz=q.size();
            nodesLeft-=sz;
            for (int i=0;i<sz;i++)
            {
                int popped=q.front();
                
                q.pop();
                int node=*adj_list[popped].begin();
                adj_list[node].erase(popped);
                if (adj_list[node].size()==1)
                {
                    
                    q.push(node);
                }
            }
            
        }
        
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};