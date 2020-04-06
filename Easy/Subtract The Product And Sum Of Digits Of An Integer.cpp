class Solution 
{
    public:
    int subtractProductAndSum(int n) 
    {
        int P=1,S=0,d=0;;
        for (int i=n;i>0;i=i/10)
        {
            d=i%10;
            P=P*d;
            S=S+d;
        }
        return P-S;
    }
};