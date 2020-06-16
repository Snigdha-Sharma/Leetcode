class Solution 
{
    public:
    int minAddToMakeValid(string S) 
    {
        stack<char> s;
        for (int i=0;i<S.size();i++)
        {
            if (S[i]=='(')
            {
                s.push('(');
            }
            else if (S[i]==')' && s.empty()==false && s.top()=='(')
            {
                s.pop();
            }
            else
            {
                s.push(S[i]);
            }
        }
        cout<<s.size();
        return s.size();
    }
};