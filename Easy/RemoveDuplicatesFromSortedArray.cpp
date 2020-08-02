class Solution 
{
    public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i=0,j=-1;
        for (int i=0;i<nums.size();i++)
        {
            while (i!=0 && i<nums.size() && nums[i]==nums[i-1])
            {
                i++;
            }
            if (i==nums.size())
            {
                
            }
            else
            {
                j++;
                nums[j]=nums[i];
            }
            
        }
        return j+1;
    }
};