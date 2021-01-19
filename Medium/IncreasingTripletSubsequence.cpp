class Solution 
{
    public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int sz=nums.size(),num1=INT_MAX,num2=INT_MAX;
        for (int i=0;i<sz;i++)
        {
            if (nums[i]<num1)
            {
                num1=nums[i];
            }
            else if (nums[i]>num1 && nums[i]<num2)
            {
                num2=nums[i];
            }
            else if (nums[i]>num2)
            {
                return true;
            }
        }
        return false;
    }
};