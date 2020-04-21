//Template1 binary search
class Solution 
{
    public:
    int guessNumber(int n) 
    {
        int l=1,r=n;
        int mid;
        int ans=0;
        while(l<=r)
        {
            mid=l+((r-l)/2);
            if (guess(mid)==0)
            {
                ans=mid;
                break;
            }
            else if (guess(mid)==1)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};