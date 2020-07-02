class Solution 
{
    public:
    int scoreOfParentheses(string S) 
    {
        int ans=0;
        stack<char> temp;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='(')
            {
                temp.push(ans);
                ans= 0;
            }
            else
            {
                ans= temp.top() + max(2*ans,1);
                temp.pop();
            }
        }
        return ans;
    }
};