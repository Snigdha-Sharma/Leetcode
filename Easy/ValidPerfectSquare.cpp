class Solution 
{
    public:
    bool isPerfectSquare(int num) 
    {
        bool ans=false;
        for (long long int i=1;i*i<=num;i++)
        {
            if (i*i==num)
            {
                ans=true;
                break;
            }
        }
        return ans;
    }
};