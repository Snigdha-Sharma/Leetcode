//To traverse each edge and maintain lexicographical ordering (on second priortiy) we need to use an extra stack
//Making adjacency list concept

class Solution 
{
    public:
    
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        unordered_map<string,priority_queue<string,vector<string>,greater<string> > > umap;
        for (int i=0;i<tickets.size();i++)
        {
            umap[tickets[i][0]].push(tickets[i][1]);
        }
        vector<string> ans;
        stack<string> st;
        stack<string> prev_ans;
        st.push("JFK");
        while(!st.empty())
        {
            if (umap[st.top()].size()==0)
            {
                prev_ans.push(st.top());
                st.pop();
            }
            else
            {
                string temp=st.top();
                st.push(umap[temp].top());
                umap[temp].pop();
            }
        }
        while(!prev_ans.empty())
        {
            ans.push_back(prev_ans.top());
            prev_ans.pop();
        }
        return ans;
    }
};