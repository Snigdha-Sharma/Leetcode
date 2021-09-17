class MapSum 
{
    public:
    /** Initialize your data structure here. */
    
    unordered_map<string,int> umap;
    
    MapSum() 
    {
        
    }
    
    void insert(string key, int val) 
    {
        if (umap.find(key)!=umap.end())
        {
            umap[key]=val;
        }
        else
        {
            umap[key]=val;
        }
    }
    
    int sum(string prefix) 
    {
        int sz=prefix.length(),ans=0;
        for (auto it=umap.begin();it!=umap.end();it++)
        {
            string tmp=it->first.substr(0,sz);
            if (tmp==prefix)
            {
                ans=ans+it->second;
            }
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */