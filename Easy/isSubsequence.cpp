class Solution 
{
    public:
    bool isSubsequence(string s, string t) 
    {
        if (s.size()==0)
        {
            return true;
        }
        int j=0;
        bool ans=false;
        for (int i=0;i<t.size();i++)
        {
            if (t[i]==s[j])
            {
                j++;
                if (j==s.size())
                {
                    ans=true;
                    break;
                }
            }
        }
        return ans;
    }
};