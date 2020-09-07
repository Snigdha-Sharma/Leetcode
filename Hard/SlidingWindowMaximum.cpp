class Solution 
{
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> ans;
        int n=nums.size();
        //Effectively for this question we need a data structure that can tell the highest element in the window at any time and whenever the window changes remove one element and add another while keeping track of largest element. We will use 2 ds one a map and another a pqueue simultaneously. We will store in map only the k elements and in pq all elements .Check in pqueue if top does not exist in map remove it and keep removing , else you have your answer for the range
        priority_queue<int> pq;
        map<int,int> m;
        for (int i=0;i<k;i++)
        {
            pq.push(nums[i]);
            if (m.find(nums[i])!=m.end())
            {
                m[nums[i]]++;
            }
            else
            {
                m[nums[i]]=1;
            }
        }
        ans.push_back(pq.top());
        for (int i=k;i<n;i++)
        {
            pq.push(nums[i]);
            if (m.find(nums[i])!=m.end())
            {
                m[nums[i]]++;
            }
            else
            {
                m[nums[i]]=1;
            }
            if(m[nums[i-k]]>1)
            {
                m[nums[i-k]]--;
            }
            else
            {
                m.erase(nums[i-k]);
            }
            while(m.find(pq.top())==m.end())
            {
                pq.pop();
            }
            ans.push_back(pq.top());
        }
        return ans;
    }
};