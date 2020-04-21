//2stacks solution O(2*n) time O(2*n) space

class Solution 
{
    public:
    bool checkValidString(string s) 
    {
        stack<int> open,ast;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='(')
            {
                open.push(i);
            }
            else if (s[i]=='*')
            {
                ast.push(i);
            }
            else if (s[i]==')')
            {
                if (open.empty()==false)
                {
                    open.pop();
                }
                else if (ast.empty()==false)
                {
                    ast.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        while(!open.empty() && !ast.empty())
        {
            if (open.top()>ast.top())
            {
                return false;
            }
            else
            {
                open.pop();
                ast.pop();
            }
        }
        return open.empty();
    }
};

//O(n) time O(1) space 2 pointer solution

class Solution 
{
    public:
    bool checkValidString(string s) 
    {
        int open=0,close=0;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='(' || s[i]=='*')
            {
                open++;
            }
            else
            {
                open--;
            }
            if (s[s.size()-1-i]==')' || s[s.size()-1-i]=='*')
            {
                close++;
            }
            else
            {
                close--;
            }
            if (open<0 || close<0)
            {
                return false;
            }
        }
        return true;
    }
};