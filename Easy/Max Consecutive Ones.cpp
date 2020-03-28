class Solution 
{
    public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int count=0,temp_count=0;
        bool flag=false;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]==1 && flag==false)
            {
                flag=true;
                temp_count=1;
            }
            else if (nums[i]==1 && flag==true)
            {
                temp_count++;
            }
            else
            {
                flag=false;
                temp_count=0;
            }
            count=max(count,temp_count);
        }
        return count;
    }
};