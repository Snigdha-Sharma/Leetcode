class Solution 
{
    public:
    
    int longestPalindrome(string s) 
    {
        vector<int> small(26,0);
        vector<int> large(26,0);
        for (int i=0;i<s.size();i++)
        {
            if (s[i]>=97 && s[i]<=122)
            {
                small[s[i]-'a']++;
            }
            else 
            {
                large[s[i]-'A']++;
            }
        }
        int ans=0;
        int odd=0;
        for (int i=0;i<26;i++)
        {
            ans=ans+2*(small[i]/2);
            ans=ans+2*(large[i]/2);
            if (odd==0 && small[i]%2==1)
            {
                odd=1;
            }
            if (odd==0 && large[i]%2==1)
            {
                odd=1;
            }
        }
        ans=odd+ans;
        return ans;
    }
};