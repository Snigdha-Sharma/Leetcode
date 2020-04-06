class Solution 
{
    public:
    int dominantIndex(vector<int>& nums) 
    {
        if (nums.size()==1)
        {
            return 0;
        }
        priority_queue<int,vector<int>,greater<int> > p;
        p.push(nums[0]);
        p.push(nums[1]);
        for (int i=2;i<nums.size();i++)
        {
            if (nums[i]>p.top())
            {
                p.push(nums[i]);
                p.pop();
            }
        }
        int smax=p.top();
        p.pop();
        int max=p.top();
        int index;
        if(max>=(2*smax))
        {
            for (int i=0;i<nums.size();i++)
            {
                if (nums[i]==max)
                {
                    index=i;
                    break;
                }
            }
            return index;
        }
        else
        {
            return -1;
        }
    }
};