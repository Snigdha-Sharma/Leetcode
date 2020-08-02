//Two Pointer Algorithm

class Solution 
{
    public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int> > ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for (int i=0;i<n-2;i++)
        {
            int l=i+1,r=n-1;
            while(l<r)
            {
                if (nums[i]+nums[l]+nums[r]==0)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    ans.push_back(temp);
                    while(l<r && nums[l]==temp[1]) l++;
                }
                else if (nums[i]+nums[l]+nums[r]<0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
             while(i<n-2 && nums[i]==nums[i+1]) i++;
        }
        
        return ans;
    }
};