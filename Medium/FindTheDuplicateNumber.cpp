class Solution 
{
    public:
    int findDuplicate(vector<int>& nums) 
    {
        unordered_set<int> input;
        for (int i=0;i<nums.size();i++)
        {
            if (input.find(nums[i])!=input.end())
            {
                return nums[i];
            }
            else
            {
                input.insert(nums[i]);
            }
        }
        return 0;
    }
};