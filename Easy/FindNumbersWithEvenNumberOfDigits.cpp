class Solution 
{
    public:
    
    int countDigits(int n)
    {
        int count=0;
        while(n>0)
        {
            count++;
            n=n/10;
        }
        return count;
    }
    
    int findNumbers(vector<int>& nums) 
    {
        int ans=0;
        for (int i=0;i<nums.size();i++)
        {
            if (countDigits(nums[i])%2==0)
            {
                ans++;
            }
        }
        return ans;
    }
};
