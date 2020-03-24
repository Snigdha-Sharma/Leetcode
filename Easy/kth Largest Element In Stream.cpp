class KthLargest 
{
    public:
    priority_queue <int, vector<int>, greater<int>> p;
    int find;
    
    
    KthLargest(int k, vector<int>& nums) 
    {
        find=k;
        for (int i=0;i<nums.size();i++)
        {
            add(nums[i]);
        }
    }
    
    int add(int val) 
    {
        if (p.size()<find)
        {
            p.push(val);
        }
        else if (val>p.top())
        {
            p.push(val);
            p.pop();
        }
        return p.top();
    }
};