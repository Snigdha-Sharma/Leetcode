class Solution 
{
    public:
    
    unordered_map<int,int> umap;
    
    int minDays(int n) 
    {
        if (n<=1)
        {
            return n;
        }
        if (umap.find(n)==umap.end())
        {
            umap[n]=1+min((n%2+minDays(n/2)),(n%3+minDays(n/3)));
        }
        return umap[n];
    }
};