class Solution 
{
    public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        //Traverse the array and for each element you find go and mark its index by making the element their negative (since array contains numbers from 1 to n inclusive) so if they are neagtive then that means their index has been visited
        vector<int> ans;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[abs(nums[i])-1]<0)
            {
                ans.push_back(abs(nums[i]));
            }
            else
            {
                nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
            }
        }
        return ans;
    }
};