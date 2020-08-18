class Solution 
{ 
    public:
    int titleToNumber(string s) 
    {
        int ans=0,n=s.size(),idx=0;
        for (int i=n-1;i>=0;i--)
        {
            ans=ans+(pow(26,idx)*(s[i]-'A'+1));
            idx++;
        }
        return ans;
    }
};