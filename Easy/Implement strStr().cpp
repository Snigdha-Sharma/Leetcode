class Solution 
{
    public:
    int strStr(string haystack, string needle) 
    {
        if (needle.size()==0)
        {
            return 0;
        }
        int i=0;
        int lps[needle.size()];
        lps[0]=0;
        if (needle.size()>haystack.size())
        {
            return -1;
        }
        int j=1;
        while (j<needle.size())
        {
            if (needle[i]==needle[j])
            {
                lps[j]=i+1;
                i++;
                j++;
            }
            else if(i)
            {
                i=lps[i-1];
            }
            else
            {
                lps[j]=0;
                j++;
            }
        }
        int y=0,x=0;
        int index=0;
        while(x<haystack.size() && y<needle.size())
        {
            if (haystack[x]==needle[y])
            {
                y++;
                x++;
            }
            else if (y)
            {
                y=lps[y-1];   
            }
            else
            {
                x++;
            }
        }
        if (y==needle.size())
        {
            return x-y;
        }
        return -1;
    }
};