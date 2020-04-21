//By applying binary search over whole range

class Solution 
{
    public:
    int mySqrt(int x) 
    {
        unsigned long int l=0,r=4294967295;
        long int mid;
        while(l<=r)
        {
            mid=l+((r-l)/2);
            if (mid*mid==x || (mid*mid<x && ((mid+1)*(mid+1))>x))
            {
                return mid;
            }
            else if (mid*mid<x)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return -1;
    }
};