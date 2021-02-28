class Solution 
{
    public:
    bool kLengthApart(vector<int>& nums, int k) 
    {
        vector<int> idx;
        for (int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                idx.push_back(i);
            }
        }
        for (int i=1;i<idx.size();i++)
        {
            //cout<<idx[i]<<" "<<idx[i-1]<<endl;
            if(idx[i]-idx[i-1]<=k)
            {
                return false;
            }
        }
        return true;
    }
};