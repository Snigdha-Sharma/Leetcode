//Time Complexity:O(N) Keep track of max where you can reach.Same as n square solution just remember things in variables
class Solution 
{
    public:
    
    int jump(vector<int>& nums) 
    {
        if (nums.size()<=1)
        {
            return 0;
        }
        if (nums.size()==2)
        {
            return 1;
        }
        
        int ans=1,till=nums[0],next=nums[0],n=nums.size();
        for (int i=1;i<nums.size()-1;i++)
        {
            next=max(next,nums[i]+i);
            next=min(next,n-1);
            
            //cout<<"Number of jumps to be taken till index "<<till<<"is "<<ans<<" and till "<<next<<" ans is "  <<ans+1<<endl;
            if (i==till)
            {
                ans++;
                till=next;
                next=0;
            }
            
        }
        
        return ans;
    }
};