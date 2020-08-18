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

//Solution by reversing
class Solution 
{
    public:
    
    void reverse(vector<int> &nums,int s,int e)
    {
        for (int i=s,j=e;i<j;i++,j--)
        {
            int t=nums[i];
            nums[i]=nums[j];
            nums[j]=t;
        }
    }
    
    void rotate(vector<int>& nums, int k) 
    {
        k=k%nums.size();
        reverse(nums,0,nums.size()-1);//Reverse the whole array
        reverse(nums,0,k-1);//Reverse first k elements again
        reverse(nums,k,nums.size()-1);//Reverse last N-k elements again
    }
};
