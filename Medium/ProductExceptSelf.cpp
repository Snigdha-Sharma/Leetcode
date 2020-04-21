//Without Division and O(n) space O(n) time
class Solution 
{
    public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> leftProduct,rightProduct;
        for (int i=0;i<nums.size();i++)
        {
            leftProduct.push_back(0);
            rightProduct.push_back(0);
        }
        leftProduct[0]=1;
        for (int i=1;i<nums.size();i++)
        {
            leftProduct[i]=leftProduct[i-1]*nums[i-1];
        }
        rightProduct[nums.size()-1]=1;
        for (int i=nums.size()-2;i>=0;i--)
        {
            rightProduct[i]=rightProduct[i+1]*nums[i+1];
        }
        for (int i=0;i<nums.size();i++)
        {
            nums[i]=leftProduct[i]*rightProduct[i];
        }
        return nums;
    }
};

//Without division and O(1) space and O(n) time
class Solution 
{
    public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> product;
        for (int i=0;i<nums.size();i++)
        {
            product.push_back(1);
        }
        long int temp=1;
        for (int i=0;i<nums.size();i++)
        {
            product[i]=temp;
            temp=temp*nums[i];
        }
        temp=1;
        for (int i=nums.size()-1;i>=0;i--)
        {
            product[i]*=temp;
            temp=temp*nums[i];
        }
        return product;
    }
};