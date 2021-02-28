class Solution 
{
    public:
    bool closeStrings(string word1, string word2) 
    {
        if (word1.size()!=word2.size())
        {
            return false;
        }
        vector<int> c1(26,0),c2(26,0);
        unordered_map<int,int> w1,w2;
        for (int i=0;i<word1.size();i++)
        {
            c1[word1[i]-'a']++;
            c2[word2[i]-'a']++;
        }
        for (int i=0;i<26;i++)
        {
            if (c1[i]!=0 && c2[i]==0)
            {
                return false;
            }
            else if (c1[i]==0 && c2[i]!=0)
            {
                return false;
            }
        }
        for (int i=0;i<26;i++)
        {
            if (c1[i]!=0)
            {
                if (w1.find(c1[i])!=w1.end())
                {
                    w1[c1[i]]++;
                }
                else
                {
                    w1[c1[i]]=1;
                }
            }
            if (c2[i]!=0)
            {
                if (w2.find(c2[i])!=w2.end())
                {
                    w2[c2[i]]++;
                }
                else
                {
                    w2[c2[i]]=1;
                }
            }
        }
        for (auto it=w1.begin();it!=w1.end();it++)
        {
            if (w2.find(it->first)==w2.end())
            {
                return false;
            }
            else if (w2[it->first]!=it->second)
            {
                return false;
            }
        }
        return true;
    }
};