class Solution 
{
    public:
    string removeDuplicates(string S) 
    {
        stack<char> s;
        for (int i=0;i<S.size();i++)
        {
            if (s.empty()==true)
            {
                s.push(S[i]);
            }
            else if (s.top()==S[i])
            {
                s.pop();
            }
            else
            {
                s.push(S[i]);
            }
        }
        string ans="";
        while(!s.empty())
        {
            ans=s.top()+ans;
            s.pop();
        }
        return ans;
    }
};