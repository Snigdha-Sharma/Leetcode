class Solution 
{
    public:
    int maxProduct(vector<int>& nums) 
    {
        long long int ans=nums[0],currP=nums[0],currN=nums[0],n=nums.size();
        for (int i=1;i<n;i++)
        {
            long long int P=currP;
            currP=max(((long long int)nums[i]),max(currP*nums[i],currN*nums[i]));
            currN=min(((long long int)nums[i]),min(P*nums[i],currN*nums[i]));
            ans=max(ans,currP);
        }
        return ans;
    }
};