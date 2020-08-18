class Solution 
{
    public:
    
    long int lcm(long int a,long int b)
    {
        //Using the fact that lcm*hcf=product of the numbers
        return a*b/__gcd(a,b);
    }
    
    int nthUglyNumber(int n, int a, int b, int c) 
    {
        //Since input integers are very large so we cannot do this like ugly number 2 and 1
        //The plus point is that the answers are limited. So we apply binary search to make use of that
        long long l=1;
        long long r=2000000000;
        long long ans;
        while(l<=r)
        {
            long long mid=l+(r-l)/2;
            long long cnt=0;
            cnt=cnt+mid/a;
            cnt=cnt+mid/b;
            cnt=cnt+mid/c;
            cnt=cnt-mid/lcm(a,b);
            cnt=cnt-mid/lcm(b,c);
            cnt=cnt-mid/lcm(a,c);
            cnt=cnt+mid/(lcm(c,lcm(a,b)));
            if(cnt<n)
            {
                 l=mid+1;
            }
            else
            {
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};