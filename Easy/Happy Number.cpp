class Solution 
{
    public:
    
    int numSquareSum(int n)
    {
        int ans=0,d=0;
        for (int i=n;i>0;i=i/10)
        {
            d=i%10;
            ans=ans+(d*d);
        }
        return ans;
    }
    
    bool isHappy(int n) 
    {
        set<int> s;
        while(1)
        {
            n=numSquareSum(n);
            if (n==1)
            {
                return true;
            }
            if (s.find(n)!=s.end())
            {
                return false;
            }
            s.insert(n);
        }
    }
};