class Solution 
{
    public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> ans;
        for (int i=0;i<numbers.size();i++)
        {
            int l=0;
            int u=numbers.size()-1;
            int mid=0;
            while(l<=u)
            {
                mid=(l+u)/2;
                if ((numbers[mid]==(target-numbers[i])) && (i!=mid))
                {
                    ans.push_back(mid+1);
                    ans.push_back(i+1);
                    sort(ans.begin(),ans.end());
                    return ans;
                }
                else if (numbers[mid]<(target-numbers[i]))
                {
                    l=mid+1;
                }
                else
                {
                    u=mid-1;
                }
            }
        }
        return ans;
    }
};