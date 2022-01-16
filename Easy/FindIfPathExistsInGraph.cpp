class Solution 
{
    public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) 
    {
        if (start==end)
        {
            return true;
        }
        vector<vector<int> > adj_list(n,vector<int> ());
        for (int i=0;i<edges.size();i++)
        {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
        }
        stack<int> st;
        st.push(start);
        unordered_set<int> visited;
        visited.insert(start);
        while(!st.empty())
        {
            int vertex=st.top();
            st.pop();
            for (int i=0;i<adj_list[vertex].size();i++)
            {
                if (adj_list[vertex][i]==end)
                {
                    return true;
                }
                else if (visited.find(adj_list[vertex][i])==visited.end())
                {
                    st.push(adj_list[vertex][i]);
                    visited.insert(adj_list[vertex][i]);
                }
            }
        }
        return false;
    }
};