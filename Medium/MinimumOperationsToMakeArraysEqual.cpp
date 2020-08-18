class Solution 
{
    public:
    int minOperations(int n) 
    {
        if (n==1)
        {
            return 0;
        }
        if (n%2==0)
        {
            n=n/2;
            return pow(n,2);
        }
        n=n/2;
        return (pow(n,2)+n);
    }
};