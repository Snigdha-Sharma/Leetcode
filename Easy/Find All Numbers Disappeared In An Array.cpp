class Solution 
{
    public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> ans;
        vector<int> count;
        for (int i=0;i<nums.size();i++)
        {
            count.push_back(0);
        }
        for (int i=0;i<nums.size();i++)
        {
            count[nums[i]-1]++;
        }
        for (int i=0;i<count.size();i++)
        {
            if (count[i]==0)
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};