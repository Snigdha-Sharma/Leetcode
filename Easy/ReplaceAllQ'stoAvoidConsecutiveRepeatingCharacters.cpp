class Solution 
{
    public:
    string modifyString(string s) 
    {
        if (s.size()==1)
        {
            if (s[0]=='?')
            {
                return "a";
            }
            return s;
        }
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='?')
            {
                for (char x='a';x<='z' && s[i]=='?';x++)
                {
                    if (i-1>=0)
                    {
                        if (x!=s[i-1])
                        {
                            s[i]=x;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    if (i+1<s.size())
                    {
                        if (x!=s[i+1])
                        {
                            s[i]=x;
                        }
                        else
                        {
                            s[i]='?';
                            continue;
                        }
                    }
                }
            }
        }
        return s;
    }
};