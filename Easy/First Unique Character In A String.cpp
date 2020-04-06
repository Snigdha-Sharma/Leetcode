class Solution 
{
    public:
    int firstUniqChar(string s) 
    {
        vector<int> freq;
        int ans=-1;
        for (int i=0;i<26;i++)
        {
            freq.push_back(0);
        }
        for (int i=0;i<s.size();i++)
        {
            freq[s[i]-97]++;
        }
        for (int i=0;i<s.size();i++)
        {
            if (freq[s[i]-97]==1)
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};