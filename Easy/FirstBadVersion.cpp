class Solution 
{
    public:
    int firstBadVersion(int n) 
    {
        int l=0,r=n;
        int mid;
        while(l<r)
        {
            mid=l+((r-l)/2);
            if (isBadVersion(mid)==false && isBadVersion(mid+1)==true)
            {
                return mid+1;
            }
            else if (isBadVersion(mid)==false)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        if(l!=n && isBadVersion(l)) 
        {
            return l;
        }
        return -1;
    }
};