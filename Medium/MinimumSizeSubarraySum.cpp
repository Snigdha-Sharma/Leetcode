class Solution 
{
    public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int n=nums.size();
        if (n==0)
        {
            return 0;
        }
        int cursum=nums[0],l=0,r=0,ans=INT_MAX;
        while(!(r==n-1 && l==n-1))
        {
            //cout<<"l="<<l<<",r="<<r<<",cursum="<<cursum<<endl;
            if (cursum<s)
            {
                if (r<n-1)
                {
                    r++;
                    //cout<<"r="<<r<<" ";
                    cursum=cursum+nums[r];
                }
                else
                {
                    //cout<<"csf="<<l<<" ";
                    cursum=cursum-nums[l];
                    l++;
                }  
            }
            else
            {
                ans=min(ans,r-l+1);
                //cout<<"Lfs="<<l<<" ";
                cursum=cursum-nums[l];
                l++;
            }
        }
        //cout<<"What";
        if (ans==INT_MAX)
        {
            return 0;
        }
        return ans;
    }
};