class Solution 
{
    public:
    
    char findKthBit(int n, int k) 
    {
        if (n==1 && k==1)
        {
            return '0';
        }
        long int sz=pow(2,n)-1;
        k--;
        char ans;
        if (k==sz/2)
        {
            return '1';
        }
        if (k<sz/2)
        {
            ans=findKthBit(n-1,k+1);
        }
        if(k>sz/2)
        {
            ans=findKthBit(n-1,sz-k);
            if (ans=='0')
            {
                ans='1';
            }
            else
            {
                ans='0';
            }
        }
        return ans;
    }
};