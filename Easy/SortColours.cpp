class Solution 
{
    public:
    void sortColors(vector<int>& nums) 
    {
        //Insertion Sort
        int j=0,key;
        for (int i=1;i<nums.size();i++)
        {
            key=nums[i];
            j=i-1;
            while(j>=0 && nums[j]>key)
            {
                nums[j+1]=nums[j];
                j--;
            }
            nums[j+1]=key;
        }
    }
};