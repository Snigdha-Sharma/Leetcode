class Solution 
{
    public:
    int minOperations(vector<int>& nums) 
    {
        int ans=0,a=INT_MIN,c=0;
        for (int i=0;i<nums.size();i++)
        {
            c=0;
            while(nums[i]>0)
            {
                if (nums[i]%2==1)
                {
                    ans++;
                }
                nums[i]=nums[i]/2;
                c++;
            }
            //cout<<"c="<<c<<endl;
            c--;
            a=max(a,c);
        }
        ans=ans+a;
        return ans;
    }
};