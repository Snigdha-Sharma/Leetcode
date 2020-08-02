class Solution 
{
    public:
    int hammingDistance(int x, int y) 
    {
        int val=x^y,count=0;
        while(val>0)
        {
            if (val&1)
            {
                count++;
            }
            val=val>>1;
        }
        return count;
    }
};