class Solution 
{
    public:
    int maxPower(string s) 
    {
        int ans=1,currans=1;
        for (int i=1;i<s.size();i++)
        {
            if (s[i]==s[i-1])
            {
                currans++;
                ans=max(ans,currans);
            }
            else
            {
                currans=1;
            }
        }
        return ans;
    }   
};