class Solution 
{
    public:
    string frequencySort(string s) 
    {
        unordered_map<char,int> umap;
        for (int i=0;i<s.size();i++)
        {
            if (umap.find(s[i])==umap.end())
            {
                umap[s[i]]=1;
            }
            else
            {
                umap[s[i]]++;
            }
        }
        priority_queue<pair<int,char> > pq;
        for (auto it=umap.begin();it!=umap.end();it++)
        {
            pq.push({it->second,it->first});
        }
        
        string ans="";
        while(!pq.empty())
        {
            int freq=pq.top().first;
            char c=pq.top().second;
            while(freq--)
                ans+=c;
            pq.pop();
        }
        return ans;
    }
};