//Binary Search Solution O(N)

class Solution 
{
    public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        vector<int> copy;
        int r=nums.size()-1;
        int l=0;
        for (auto i=nums.begin();i!=nums.end();i++)
        {
            copy.push_back(*i);
        }
        sort(nums.begin(),nums.end());
        int c=0;
        while(l<r)
        {
            if (nums[l]+nums[r]==target)
            {
                for (auto i=copy.begin();i!=copy.end();i++)
                {
                    if (*i==nums[l] || *i==nums[r])
                    {
                        ans.push_back(c);
                    }
                    c++;
                }
                break;
            }
            else if (nums[l]+nums[r]<target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};

//Sorting and two pointer search O(N log N)

class Solution 
{
    public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        int n=nums.size();
        vector<pair<int,int> > helper;
        for (int i=0;i<n;i++)
        {
            helper.push_back(make_pair(nums[i],i));
        }
        sort(helper.begin(),helper.end());//O(n log n)
        int i=0,j=n-1;
        while(i<j)//O(n)
        {
            int sum=helper[i].first+helper[j].first;
            if (sum==target)
            {
                ans.push_back(helper[i].second);
                ans.push_back(helper[j].second);
                return ans;
            }
            else if (sum<target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }
};

//Brute Force Approach
class Solution 
{
    public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        for (int i=0;i<nums.size();i++)
        {
            for (int j=i+1;j<nums.size();j++)
            {
                if (nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};