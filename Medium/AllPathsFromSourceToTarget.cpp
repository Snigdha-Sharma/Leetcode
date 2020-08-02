//Understood but couldn't do myself
//Understand implementing dfs using recursion

class Solution 
{
    public:
    
    int target;//To know the target node
    vector<vector<int>> res;//answer
    vector<int> tmp;
    
    void dfs(vector<vector<int>>& graph, int currNode) 
    {
        tmp.push_back(currNode);
        if (currNode==target)
        {
            res.push_back(tmp);
        }
        else 
        {
            for (int node: graph[currNode]) 
            {
                dfs(graph, node);
            }
        }
        tmp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        target=graph.size()-1;
        dfs(graph,0);
        return res;
    }
};