class Solution 
{
    public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        set<vector<int> > ans;
        int n=nums.size();
        long int N=pow(2,n);
        for (long int i=0;i<N;i++)
        {
            vector<int> temp;
            for (int j=0;j<n;j++)
            {
                if (i&(1<<j))
                {
                    temp.push_back(nums[j]);
                }
            }
            sort(temp.begin(),temp.end());
            ans.insert(temp);
        }
        vector<vector<int> > A;
        for (auto it=ans.begin();it!=ans.end();it++)
        {
            A.push_back(*it);
        }
        return A;
    }
};