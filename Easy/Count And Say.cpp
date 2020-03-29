class Solution 
{
    public:
    
    string s,ans="";
    
    string countAndSay(int n) 
    {
        if (n==1)
        {
            return "1";
        }
        s=countAndSay(n-1);
        int count=1;
        ans="";
        for (int i=1;i<s.size();i++)
        {
            if (s[i]==s[i-1])
            {
                count++;
            }
            else
            {
                ans=ans+to_string(count);
                ans=ans+s[i-1];
                count=1;
            }
        }
        ans=ans+to_string(count);
        ans=ans+s[s.size()-1];
        return ans;
    }
};