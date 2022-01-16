class Solution 
{
    public:
    
    vector<int> ans;
    
    //All those nodes which will be a part of the cycle will not end at a terminal node ever. So answer is all nodes which are not part of cycle
    bool isCyclic(vector<vector<int>>& graph,int node,vector<int> &visited)
    {
        if (visited[node]==2)
        {
            return true;
        }
        visited[node]=2;
        for (int i=0;i<graph[node].size();i++)
        {
            if (visited[graph[node][i]]!=1)
                if (isCyclic(graph,graph[node][i],visited)==true)
                    return true;
        }
        visited[node]=1;
        ans.push_back(node);
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int> visited(n,0);
        for (int i=0;i<n;i++)
        {
            if (visited[i]==0)
                isCyclic(graph,i,visited);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};