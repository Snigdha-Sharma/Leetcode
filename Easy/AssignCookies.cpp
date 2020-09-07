class Solution 
{
    public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        priority_queue<int> cookies,people;
        for (int i=0;i<s.size();i++)
        {
            cookies.push(s[i]);
        }
        for (int i=0;i<g.size();i++)
        {
            people.push(g[i]);
        }
        int ans=0;
        while(cookies.size()>0 && people.size()>0)
        {
            if (cookies.top()>=people.top())
            {
                cookies.pop();
                people.pop();
                ans++;
            }
            else 
            {
                people.pop();
            }
        }
        return ans;
    }
};