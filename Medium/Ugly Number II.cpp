class Solution 
{
    public:
    int nthUglyNumber(int n) 
    {
        if (n==0)
            return 1;
        long int ugly[n];
        ugly[0]=1;
        int i2=0,i3=0,i5=0;
        long int nexti2=0,nexti3=0,nexti5=0;
        nexti2=2;
        nexti3=3;
        nexti5=5;
        for (long int i=1;i<n;i++)
        {
            ugly[i]=min(nexti2,min(nexti3,nexti5));
            if (ugly[i]==nexti2)
            {
                i2++;
                nexti2=ugly[i2]*2;
            }
            if (ugly[i]==nexti3)
            {
                i3++;
                nexti3=ugly[i3]*3;
            }
            if (ugly[i]==nexti5)
            {
                i5++;
                nexti5=ugly[i5]*5;
            }
        }
        return ugly[n-1];
    }
};