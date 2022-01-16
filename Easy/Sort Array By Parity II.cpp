class Solution 
{
    public:
    vector<int> sortArrayByParityII(vector<int>& A) 
    {
        vector<int> even;
        vector<int> odd;
        for (int i=0;i<A.size();i++)
        {
            if (A[i]%2==0)
            {
                even.push_back(A[i]);
            }
            else
            {
                odd.push_back(A[i]);
            }
        }
        int i=0,j=0;
        while(j<even.size())
        {
            A[i]=even[j];
            i=i+2;
            j++;
        }
        i=1,j=0;
        while(j<odd.size())
        {
            A[i]=odd[j];
            i=i+2;
            j++;
        }
        return A;
    }
};

//In place solution
class Solution 
{
    public:
    vector<int> sortArrayByParityII(vector<int>& nums) 
    {
        int even=0,odd=1;
        for (;even<nums.size();even+=2)
        {
            if (nums[even]%2==1)
            {
                while(nums[odd]%2==1)
                {
                    odd+=2;
                }
                int t=nums[even];
                nums[even]=nums[odd];
                nums[odd]=t;
            }
        }
        return nums;
    }
};