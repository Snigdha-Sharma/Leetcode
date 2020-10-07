class Solution 
{
    public:
    
    void show(vector<int> &a)
    {
        for (int i=0;i<a.size();i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    
    int firstMissingPositive(vector<int>& nums) 
    {
        int n=nums.size();
        bool hasOne=false;
        for (int i=0;i<n;i++)
        {
            if (nums[i]==1)
            {
                hasOne=true;
                break;
            }
        }        
        if (!hasOne)
        {
            return 1;
        }
        for (int i=0;i<n;i++)
        {
            if (nums[i]<=0)
            {
                nums[i]=1;
            }
        }
        for (int i=0;i<n;i++)
        {
            if (abs(nums[i])<=n && abs(nums[i])>=1 && nums[abs(nums[i])-1]>0)
            { 
                nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
            }
        }
        for(int i=2;i<=n;i++)
        {
            if (nums[i-1]>0)
            {
                return i;
            }
        }
        return n+1;
    }
};