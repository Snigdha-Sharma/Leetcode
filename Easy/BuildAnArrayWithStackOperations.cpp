class Solution 
{
    public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        int t=0;
        vector<string> ans;
        for (int i=1;i<=n && t<target.size();i++)
        {
            if (target[t]==i)
            {
                ans.push_back("Push");
                t++;
            }
            else 
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};