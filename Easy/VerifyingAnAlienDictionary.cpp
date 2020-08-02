class Solution 
{
    public:
    
    bool isAlienSorted(vector<string>& words, string order) 
    {
        unordered_map<char,char> umap;
        string help="abcdefghijklmnopqrstuvwxyz";
        for (int i=0;i<order.size();i++)
        {
            umap[order[i]]=help[i];
        }
        vector<string> orig;
        for (int i=0;i<words.size();i++)
        {
            string val="";
            for (int j=0;j<words[i].size();j++)
            {
                val=val+umap[words[i][j]];
            }
            orig.push_back(val);
        }
        return is_sorted(orig.begin(),orig.end());
    }
};