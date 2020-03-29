class Solution 
{
    public:
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        unordered_map<int,int> umap;
        for (int i=0;i<deck.size();i++)
        {
            umap[deck[i]]++;
        }
        int X=umap[0];
        for (int i=1;i<umap.size();i++)
        {
            X=__gcd(X,umap[i]);
        }
        if (X>=2)
        {
            return true;
        }
        return false;
    }
};