class Solution 
{
    public:
    string removeDuplicateLetters(string s) 
    {
        int n=s.size();
        unordered_map<char,int> umap;
        string ans;
        for (int i=0;i<n;i++)
        {
            umap[s[i]]++;
        }
        if(ans.size()==umap.size())
        {
            return ans;
        }
        for(int i=0;i<n;i++)
        {
            while(ans.size()>0 && ans.back()>s[i] && umap[ans.back()]>0 && ans.find(s[i])==-1)
            {
                ans.pop_back();
            }
            if(ans.find(s[i])==-1)
            {
                ans.push_back(s[i]);
            }
            umap[s[i]]--;
        }    
        return ans;
    }
};