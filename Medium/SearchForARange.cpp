//Good question of template 3 of binary search

class Solution 
{
    public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> ans;
        if (nums.size() == 0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        int l=0,r=nums.size()-1;
        int mid;
        int flag=0;
        while(l+1<r)
        {
            mid=l+((r-l)/2);
            if (nums[mid]==target && nums[mid-1]!=target)
            {
                ans.push_back(mid);
                flag=1;
                break;
            }
            else if (nums[mid]>=target)
            {
                r=mid;
            }
            else
            {
                l=mid;
            }
        }
        if (flag==0 && nums[l]==target)
        {
            ans.push_back(l);
        }
        else if (flag==0 && nums[r]==target)
        {
            ans.push_back(r);
        }
        l=0,r=nums.size()-1,flag=0;
        while(l+1<r)
        {
            mid=l+((r-l)/2);
            if (nums[mid]==target && nums[mid+1]!=target)
            {
                flag=1;
                ans.push_back(mid);
                break;
            }
            else if (nums[mid]<=target)
            {
                l=mid;
            }
            else
            {
                r=mid;
            }
        }
        if (flag==0 && nums[r]==target)
        {
            ans.push_back(r);
        }
        else if (flag==0 && nums[l]==target)
        {
            ans.push_back(l);
        }
        if (ans.size()==0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};