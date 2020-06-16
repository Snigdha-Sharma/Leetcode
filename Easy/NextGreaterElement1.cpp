class Solution 
{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        if (nums1.size()==0)
        {
            return ans;
        }
        stack<int> s;
        map<int,int> m;
        s.push(nums2[0]);
        for (int i=1;i<nums2.size();i++)
        {
            if (s.empty())
            {
                s.push(nums2[i]);
                continue;
            }
            while (s.empty()==false && nums2[i]>s.top())
            {
                m[s.top()]=nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        while(s.empty()==false)
        {
            m[s.top()]=-1;
            s.pop();
        }
       
        for (int i=0;i<nums1.size();i++)
        {
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};