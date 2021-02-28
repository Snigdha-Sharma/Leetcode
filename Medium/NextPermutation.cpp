//Question is basically focussed on making us understand how we get the next permutation of an array at any given instance.
//When we make next permuations we are basically moving from a state of complete order (lets assume ascending) to complete disorder. So let us traverse our array from
//the right and whenever we find the first order i.e. arr[i-1]<arr[i] we will try to break that order. Now since eleemnt at arr[i-1] is maintaining order let us replace 
//it with an element just greater than it present in the rightward series to get the just next permutation.

class Solution 
{
    public:
    void nextPermutation(vector<int>& nums) 
    {
        for (int i=nums.size()-1;i>0;i--)
        {
            if (nums[i-1]<nums[i])
            {
                int x=nums[i-1];
                for (int j=i;j<nums.size();j++)
                {
                    if (j+1==nums.size() || (nums[j]>x && nums[j+1]<=x))
                    {
                        nums[i-1]=nums[j];
                        nums[j]=x;
                        break;
                    }
                }
                sort(nums.begin()+i,nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end());
    }
};