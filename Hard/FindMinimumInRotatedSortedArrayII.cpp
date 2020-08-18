//0 1 2 3 4 5 5 6 6 7 7->Normal ascending sorted array
//5 6 6 7 7 0 1 2 3 4 5->Rotated ascending sorted array where nums[mid]<nums[r]
//5 5 6 6 7 7 0 1 2 3 4->Rotated ascending sorted array where nums[mid]>nums[r]
//3 3 3 3 0 1 3->Rotated ascending sorted array when elements are repeated and nums[mid]=nums[r]


class Solution 
{
    public:
    int findMin(vector<int>& nums) 
    {
        int l=0,r=nums.size()-1,mid=0;
        while(l<r)
        {
            mid=l+(r-l)/2;
            if (nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else if (nums[mid]<nums[r])
            {
                r=mid;
            }
            else
            {
                r--;
            }
        }
        return nums[r];
    }
};