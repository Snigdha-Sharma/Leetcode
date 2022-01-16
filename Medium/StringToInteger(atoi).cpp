class Solution 
{
    public:
    int myAtoi(string s) 
    {
        int ans=0,i=0,sign=1;
        
        //Read in and ignore any leading whitespace
        while(i<s.size() && s[i]==' ')
        {
            i++;
        }
        
        //Check if the next character  is '-' or '+'
        if (i<s.size())
        {
            if (s[i]=='-')
            {
                sign=-1;
                i++;
            }
            else if (s[i]=='+')
            {
                i++;
            }
        }
        
        while(i<s.size())
        {
            
            if (s[i]>='0' && s[i]<='9')
            {
                if (ans==(INT_MAX/10))
                {
                    if ('7'-s[i]>=0)
                    {
                        ans=ans*10+(sign*(s[i]-'0'));
                    }
                    else
                    {
                        ans=INT_MAX;
                    }
                }
                else if (ans==INT_MIN/10)
                {
                    if ('8'-s[i]>=0)
                    {
                        ans=ans*10+(sign*(s[i]-'0'));
                    }
                    else
                    {
                        ans=INT_MIN;
                    }
                }
                else if (ans>INT_MAX/10)
                {
                    ans=INT_MAX;
                }
                else if (ans<INT_MIN/10)
                {
                    ans=INT_MIN;
                }
                else if (ans>INT_MIN/10 && ans<INT_MAX/10)
                {
                    ans=ans*10+(sign*(s[i]-'0'));
                }
            }
            else
            {
                break;
            }
            i++;
        }
        
        return ans;
    }
};