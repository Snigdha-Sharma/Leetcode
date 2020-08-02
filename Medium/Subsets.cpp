class Solution 
{
    public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int> > ans;
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
            ans.push_back(temp);
        }
        return ans;
    }
};