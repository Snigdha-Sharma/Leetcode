class Solution 
{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<pair<string,int> > temp;
        for (int i=0;i<strs.size();i++)
        {
            temp.push_back(make_pair(strs[i],i));
        }
        for (int i=0;i<temp.size();i++)
        {
            sort(temp[i].first.begin(),temp[i].first.end());
        }
        sort(temp.begin(),temp.end());
        vector<vector<string> > ans;
        vector<string> m;
        m.push_back(strs[temp[0].second]);
        for (int i=1;i<temp.size();i++)
        {
            if (temp[i].first!=temp[i-1].first)
            {
                ans.push_back(m);
                m.clear();
            }
            m.push_back(strs[temp[i].second]);
        }
        ans.push_back(m);
        return ans;
    }
};