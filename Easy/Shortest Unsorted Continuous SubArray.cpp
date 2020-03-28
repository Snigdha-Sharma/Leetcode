class Solution 
{
    public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        vector<int> original;
        for (int i=0;i<nums.size();i++)
        {
            original.push_back(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int p=0,q=nums.size()-1;
        for ( ;p<nums.size();p++)
        {
            if (nums[p]!=original[p])
            {
                break;
            }
        }
        for ( ;q>p;q--)
        {
            if (nums[q]!=original[q])
            {
                break;
            }
        }
        return q-p+1;
    }
};