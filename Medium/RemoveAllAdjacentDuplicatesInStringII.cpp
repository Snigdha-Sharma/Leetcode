class Solution 
{
    public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char,int> > st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty()==true || st.top().first!=s[i])
            {
                st.push({s[i],1});
            }
            else if(st.top().first==s[i] && st.top().second==k-1)
            {
                st.pop();
            }
            else
            {
                st.top().second++;
            }
        }
        string ans="";
        while(!st.empty())
        {
            for (int i=0;i<st.top().second;i++)
            {
                ans=st.top().first+ans;
            }
            st.pop();
        }
        return ans;
    }
};