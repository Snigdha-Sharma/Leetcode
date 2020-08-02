class Solution 
{
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> umap;
        for (int i=0;i<nums.size();i++)
        {
            if (umap.find(nums[i])==umap.end())
            {
                umap[nums[i]]=1;
            }
            else
            {
                umap[nums[i]]++;
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        for (auto it=umap.begin();it!=umap.end();it++)
        {
            if (pq.size()<k)
            {
                pq.push(make_pair(it->second,it->first));
            }
            else if (it->second>=pq.top().first)
            {
                pq.push(make_pair(it->second,it->first));
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};