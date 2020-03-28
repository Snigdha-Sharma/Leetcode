class Solution 
{
    public:
    int thirdMax(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums[nums.size()-((nums.size() >= 3) ? 3 : 1)];
    }
};