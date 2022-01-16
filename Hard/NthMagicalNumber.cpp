class Solution 
{
    public:
    //Find the pattern problem
    int nthMagicalNumber(int n, int a, int b) 
    {
        long long int lcm=(a*b)/__gcd(a,b),mod=1e9+7;
        long long int N=lcm/a+lcm/b-1;
        long long int Q=n/N,R=n%N,start=(Q*lcm)%mod;
        if (R==0)
        {
            return (int)start;
        }
        int heads[2]={a,b};
        for (int i=0;i<R-1;i++)
        {
            if (heads[0]<=heads[1])
            {
                heads[0]+=a;
            }
            else
            {
                heads[1]+=b;
            }
        }
        start+=min(heads[0],heads[1]);
        return start%mod;
    }
};