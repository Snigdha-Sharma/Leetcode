class Solution 
{
    public:
    int missingNumber(vector<int>& nums) 
    {
        int sum=((nums.size())*(nums.size()+1))/2;
        int ex=0;
        for (int i=0;i<nums.size();i++)
        {
            ex=ex+nums[i];
        }
        if (ex==sum)
        {
            return 0;
        }
        else
        {
            return sum-ex;
        }
    }
};