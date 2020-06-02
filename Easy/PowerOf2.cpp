class Solution 
{
    public:
    bool isPowerOfTwo(int n) 
    {
        long int k=(long int)n;
        if (n==0)
        {
            return false;
        }
        if ((k&(k-1))==0)
        {
            return true;
        }
        return false;
    }
};