class Solution 
{
    public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        if (nums.size()==0)
        {
            return 0;
        }
        int curr_len=1,max_len=1;
        for (int i=1;i<nums.size();i++)
        {
            if (nums[i]>nums[i-1])
            {
                curr_len++;
            }
            else
            {
                max_len=max(max_len,curr_len);
                curr_len=1;
            }
        }
        max_len=max(curr_len,max_len);
        return max_len;
    }
};