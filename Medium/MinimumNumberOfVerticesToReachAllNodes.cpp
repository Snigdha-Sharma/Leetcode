//Just count all nodes which dont have parents . Nodes who dont have parents will need to be traversed by us. Rest can be reached anyhow

class Solution 
{
    public:
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int> ans;
        set<int> s;
        for (int i=0;i<edges.size();i++)
        {
            s.insert(edges[i][1]);
        }
        for (int i=0;i<n;i++)
        {
            if (s.find(i)==s.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};