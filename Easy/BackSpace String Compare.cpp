//Solution using stack O(N) space O(N) time

class Solution 
{
    public:
    bool backspaceCompare(string S, string T) 
    {
        stack<char> s,t;
        string l="",k="";
        for (int i=0;i<S.size();i++)
        {
            if (S[i]=='#' && s.empty()==false)
            {
                s.pop();
            }
            else if (S[i]=='#' && s.empty()==true)
            {
            
            }
            else
            {
                s.push(S[i]);
            }
        }
        for (int i=0;i<T.size();i++)
        {
            if (T[i]=='#' && t.empty()==false)
            {
                t.pop();
            }
            else if (T[i]=='#' && t.empty()==true)
            {
            
            }
            else
            {
                t.push(T[i]);
            }
        }
        while(!s.empty())
        {
            l=l+s.top();
            s.pop();
        }
        while(!t.empty())
        {
            k=k+t.top();
            t.pop();
        }
        if (l==k)
        {
            return true;
        }
        return false;
    }
};


//Solution in O(1) space
class Solution 
{
    public:
    bool backspaceCompare(string S, string T) 
    {
        int i=S.size()-1,j=T.size()-1;
        while(i>=0 || j>=0)
        {
            int count=0;
            while(i>=0 && (count>0 || S[i]=='#'))
            {
                if(S[i]=='#')
                {
                    count++;
                }
                else
                {
                    count--;
                }
                i--;
            }
            while(j>=0 && (count>0 || T[j]=='#'))
            {
                if(T[j]=='#')
                {
                    count++;
                }
                else
                {
                    count--;
                }
                j--;
            }
            if (i>=0 && j>=0)
            {
                if (S[i]!=T[j])
                {
                    return false;
                }
                else
                {
                    i--;
                    j--;
                }
            }
            else
            {
                if (i>=0 || j>=0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};