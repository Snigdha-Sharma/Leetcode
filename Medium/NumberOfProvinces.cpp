class Solution 
{
    public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int N=isConnected.size(),ans=0;
        unordered_set<int> visited;
        for (int i=0;i<N;i++)
        {
            if (visited.find(i)==visited.end())
            {
                stack<int> st;
                st.push(i);
                visited.insert(i);
                while(!st.empty())
                {
                    int el=st.top();
                    st.pop();
                    for (int j=0;j<N;j++)
                    {
                        if (isConnected[el][j]==1 && visited.find(j)==visited.end())
                        {
                            st.push(j);
                            visited.insert(j);
                        }
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};