class Solution 
{
    public:
    string convertToTitle(int n) 
    {
        string ans="";
        while(n>0)
        {
            n--;//Because mod gives range from 0 to 25
            int x=n%26;
            char c=x+65;
            ans=c+ans;
            n=n/26;
        }
        return ans;
    }
};