//The concept that we use here is that at first multiple occurences of the same element just increase that elemenet's total worth. Now for each element we have to make a
//choice as to select it or not for obtaining the maximum worth. Now choosing or not choosing a element merely depends on whether its neighbours are giving more worth
//than the element itself or not. This choice depeneds on your past choices as well so you have to keep updating your dp table too.
 
class Solution 
{
    public:
    
    void show(vector<int> &A)
    {
        for (int i=0;i<A.size();i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
    
    int deleteAndEarn(vector<int>& nums) 
    {
        if (nums.size()==0)
        {
            return 0;
        }
        vector<int> dp(10001,0);
        int maxi=-1;
        for (int i=0;i<nums.size();i++)
        {
            maxi=max(maxi,nums[i]);
            dp[nums[i]]++;
        }
        
        for (int i=2;i<=maxi;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+(dp[i]*i));
        }
        return dp[maxi];
    }
};