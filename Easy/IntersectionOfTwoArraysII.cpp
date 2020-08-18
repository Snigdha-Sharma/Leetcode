class Solution 
{
    public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int,pair<int,int> > umap;
        for (int i=0;i<nums1.size();i++)
        {
            if (umap.find(nums1[i])!=umap.end())
            {
                umap[nums1[i]].first++;
            }
            else
            {
                umap[nums1[i]].first=1;
            }
        }
        for (int i=0;i<nums2.size();i++)
        {
            if (umap.find(nums2[i])!=umap.end())
            {
                umap[nums2[i]].second++;
            }
            else
            {
                umap[nums2[i]].second=1;
            }
        }
        vector<int> ans;
        for(auto it=umap.begin();it!=umap.end();it++)
        {
            int count=min(it->second.first,it->second.second);
            for(int i=0;i<count;i++)
            {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};