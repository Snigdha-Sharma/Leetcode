class Solution 
{
    public:
    
    bool isValidUpper(char a)
    {
        if (a>=65 && a<=90)
        {
            return true;
        }
        return false;
    }
    
    bool isValidLower(char a)
    {
        if (a>=97 && a<=122)
        {
            return true;
        }
        return false;
    }
    
    bool isNumeric(char a)
    {
        if (a>=48 && a<=57)
        {
            return true;
        }
        return false;
    }
    
    bool isPalindrome(string s) 
    {
        if (s.size()==0)
        {
            return true;
        }
        int i=0,j=s.size()-1,flag=1;
        while(i<j)
        {
            if (!isValidUpper(s[i]) && !isValidLower(s[i]) && !isNumeric(s[i]))
            {
                i++;
            }
            else if (!isValidUpper(s[j]) && !isValidLower(s[j]) && !isNumeric(s[j]))
            {
                j--;
            }
            else if (!isNumeric(s[i]) && !isNumeric(s[j]) && (s[i]==s[j] || s[i]==s[j]+32 || s[j]==s[i]+32))
            {
                i++;
                j--;
            }
            else if(isNumeric(s[i]) && isNumeric(s[j]) && (s[i]==s[j]))
            {
                i++;
                j--;
            }
            else
            {
                flag=0;
                break;
            }
        }
        if (flag==0)
        {
            return false;
        }
        return true;
    }
};