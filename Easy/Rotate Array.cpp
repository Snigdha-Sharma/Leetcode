class Solution 
{
    public:
    void rotate(vector<int>& nums, int k) 
    {
        if (k>nums.size())
        {
            k=k%nums.size();
        }
        if (k==0)
        {
            return;
        }
        int temp[k];
        for (int i=nums.size()-k,j=0;i<nums.size();i++,j++)
        {
            temp[j]=nums[i];
        }
        for (int i=nums.size()-1;i>=k;i--)
        {
            nums[i]=nums[i-k];
        }
        for (int i=0;i<k;i++)
        {
            nums[i]=temp[i];
        }
    }
};