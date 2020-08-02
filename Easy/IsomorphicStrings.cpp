class Solution 
{
    public:
    bool wordPattern(string pattern, string str) 
    {
        unordered_map<char,string> umap1;
        unordered_map<string,char> umap2;
        vector<string> tokens;
        stringstream check1(str);
        string intermediate;
        while(getline(check1,intermediate,' '))
        {
            tokens.push_back(intermediate);
        }
        if (tokens.size()!=pattern.size())
        {
            return false;
        }
        for (int i=0;i<pattern.size();i++)
        {
            if (umap1.find(pattern[i])==umap1.end() && umap2.find(tokens[i])==umap2.end())
            {
                umap1[pattern[i]]=tokens[i];
                umap2[tokens[i]]=pattern[i];
            }
            else
            {
                if (umap1[pattern[i]]!=tokens[i] || umap2[tokens[i]]!=pattern[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};