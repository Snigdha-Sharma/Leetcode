class Solution 
{
    public:
    void moveZeroes(vector<int>& nums) 
    {
        int c=count(nums.begin(), nums.end(), 0);
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
        while(c--)
        {
            nums.push_back(0);
        }
    }
};