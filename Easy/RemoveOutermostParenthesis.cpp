class Solution 
{
    public:
    string removeOuterParentheses(string S) 
    {
        stack<char> s;
        vector<int> partitions;
        for (int i=0;i<S.size();i++)
        {
            if (S[i]=='(')
            {
                s.push('(');
            }
            else
            {
                s.pop();
                if (s.empty()==true)
                {
                    partitions.push_back(i);
                }
            }
        }
        string ans="";
        int start=1;
        for (int i=0;i<partitions.size();i++)
        {
            string a=S.substr(start,partitions[i]-start);
            ans=ans+a;
            start=partitions[i]+2;
        }
        return ans;
    }
};