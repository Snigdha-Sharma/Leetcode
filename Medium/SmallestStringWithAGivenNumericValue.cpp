class Solution 
{
    public:
    string getSmallestString(int n, int k) 
    {
        string ans(n,'a');
        k=k-n;
        for (int i=n-1;i>=0,k>0;i--)
        {
            ans[i]=ans[i]+min(25,k);
            k=k-25;
        }
        return ans;
    }
};