class Solution 
{
    public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        //Keep marking the value at index of the number that you have seen as negative. when you are going to mark chekc if already value there was negative. 
        //If it was it means cell was already makred before. That is that number if duplicate
        vector<int> ans;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[abs(nums[i])-1]<0)
            {
                ans.push_back(abs(nums[i]));
            }
            else
            {
               nums[abs(nums[i])-1] =-nums[abs(nums[i])-1];
            }
        }
        
        return ans;
    }
};