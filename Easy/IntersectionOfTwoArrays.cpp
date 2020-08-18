class Solution 
{
    public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        set<int> s;
        for (int i=0;i<nums2.size();i++)
        {
            s.insert(nums2[i]);
        }
        vector<int> temp;
        for (auto it=s.begin();it!=s.end();it++)
        {
            temp.push_back(*it);
        }
        
        sort(nums1.begin(),nums1.end());
        for (int i=0;i<temp.size();i++)
        {
            int el=temp[i];
            int l=0,r=nums1.size()-1,mid;
            while(l<=r)
            {
                mid=l+(r-l)/2;
                if (nums1[mid]==el)
                {
                    ans.push_back(el);
                    break;
                }
                else if (nums1[mid]<el)
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        return ans;
    }
};