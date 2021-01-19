class Solution 
{
    public:
    int maxCoins(vector<int>& nums) 
    {
        int sz=nums.size();
        vector<int> nums2(sz+2,0);
        nums2[0]=1;
        nums2[sz+1]=1;
        for (int i=1;i<=sz;i++)
        {
            nums2[i]=nums[i-1];
        }
        vector<vector<int> > dp(sz+2,vector<int> (sz+2,0));
        for (int length=1;length<sz+1;length++) 
        { 
            for (int left=1;left<sz-length+2;left++) 
            { 
                int right=left+length-1; 
                for (int last=left;last<right+1;last++) 
                { 
                    dp[left][right]=max(dp[left][right],dp[left][last-1]+nums2[left-1]*nums2[last]*nums2[right+1]+dp[last+1][right]); 
                } 
            } 
        } 
        return dp[1][sz]; 
    }
};