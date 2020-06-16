class Solution 
{
    public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
        vector<int> ans;
        for (int i=0;i<T.size();i++)
        {
            ans.push_back(0);
        }
        stack<pair<int,int> > s;
        s.push(make_pair(T[0],0));
        for (int i=1;i<T.size();i++)
        {
            while (s.empty()==false && T[i]>s.top().first)
            {
                ans[s.top().second]=i-s.top().second;
                s.pop();
            }
            s.push(make_pair(T[i],i));
        }
        return ans;
    }
};