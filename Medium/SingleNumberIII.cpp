//First separate the two unique numbers in 2 different lists using the fact that when we XOR the whole array we get the XOR of both the unique numbers. Now this XOR 
//has those bits set where both the unique numbers have oppposite bits . After that simply XOR the 2 lists separately

class Solution 
{
    public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int resXOR=0;
        for (int i=0;i<nums.size();i++)
        {
            resXOR=resXOR^nums[i];
        }
        int pos=0;
        while(1)
        {
            if (resXOR&(1<<pos))
            {
                break;
            }
            pos++;
        }
        int n=1<<pos;
        vector<int> setbit,unsetbit;
        for (int i=0;i<nums.size();i++)
        {
            if (n & nums[i])
            {
                setbit.push_back(nums[i]);
            }
            else
            {
                unsetbit.push_back(nums[i]);
            }
        }
        int num1=0,num2=0;
        for (int i=0;i<setbit.size();i++)
        {
            num1=num1^setbit[i];
        }
        for (int i=0;i<unsetbit.size();i++)
        {
            num2=num2^unsetbit[i];
        }
        vector<int> ans;
        ans.push_back(num1);
        ans.push_back(num2);
        return ans;
    }
};