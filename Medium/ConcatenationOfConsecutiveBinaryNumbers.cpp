class Solution 
{
    public:
    int concatenatedBinary(int n) 
    {
        long long int res=0,mod=1e9+7,currLen=0;
        for (int i=1;i<=n;i++) 
        {
            if ((i&(i-1))==0)
            {
                currLen++;
            }
            res=(res<<currLen)%mod;
            res+=i%mod;
        }
        return res;
    }
};