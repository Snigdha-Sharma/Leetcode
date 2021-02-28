class Solution 
{
    public:
    bool isAnagram(string s, string t) 
    {
        if(s.size()!=t.size())
        {
            return false;
        }
        unordered_map<char,int> umaps,umapt;
        for(int i=0;i<s.size();i++)
        {
            if(umaps.find(s[i])!=umaps.end())
            {
                umaps[s[i]]++;
            }
            else
            {
                umaps[s[i]]=1;
            }
        }
        for(int i=0;i<t.size();i++)
        {
            if(umapt.find(t[i])!=umapt.end())
            {
                umapt[t[i]]++;
            }
            else
            {
                umapt[t[i]]=1;
            }
        }
        for(auto it=umaps.begin();it!=umaps.end();it++)
        {
            if(umapt.find(it->first)!=umapt.end())
            {
                if(it->second!=umapt[it->first])
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};