class Solution 
{
    public:
    int findLHS(vector<int>& nums) 
    {
        unordered_map<int,int> umap;
        for (int i=0;i<nums.size();i++)
        {
            if (umap.find(nums[i])!=umap.end())
            {
                umap[nums[i]]++;
            }
            else
            {
                umap[nums[i]]=1;
            }
        }
        vector<pair<int,int> > v;
        for (auto it=umap.begin();it!=umap.end();it++)
        {
            v.push_back(make_pair(it->first,it->second));
        }
        sort(v.begin(),v.end());
        int ans=0;
        for (int i=1;i<v.size();i++)
        {
            if ((v[i].first-v[i-1].first)==1)
            {
                ans=max(ans,v[i-1].second+v[i].second);   
            }
        }
        return ans;
    }
};