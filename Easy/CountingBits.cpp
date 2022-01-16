class Solution 
{
    public:
    vector<int> countBits(int n) 
    {
        //DP relation is based on the fact that when you add a 0 at the end of a number's bit representation number becomes double. So, if wew know the answer of half of it we use it and add 0 or 1 depending on whether number is odd or even
        vector<int> ans(n+1,-1);
        ans[0]=0;
        for (int i=1;i<=n;i++)
        {
            ans[i]=ans[i>>1]+i%2;
        }
        return ans;
    }
};