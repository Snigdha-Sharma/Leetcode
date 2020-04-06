class Solution 
{
    public:
    int findShortestSubArray(vector<int>& nums) 
    {
        vector<int> freq;
        for (int i=0;i<50000;i++)
        {
            freq.push_back(0);
        }
        for (int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        vector<int> degree;
        int g=freq[0];
        for (int i=1;i<freq.size();i++)
        {
            g=max(g,freq[i]);
        }
        vector<int> start;
        vector<int> end;
        for (int i=0;i<freq.size();i++)
        {
            if (freq[i]==g)
            {
                degree.push_back(i);
            }
        }
        
        for (int j=0;j<degree.size();j++)
        {
            int front=0,back=nums.size()-1;
            while(front<nums.size())
            {
                if (nums[front]==degree[j])
                {
                    start.push_back(front);
                    break;
                }
                front++;
            }
            while(back>=0)
            {
                if (nums[back]==degree[j])
                {
                    end.push_back(back);
                    break;
                }
                back--;
            }
        }
        
        int m=INT_MAX;
        for (int i=0;i<degree.size();i++)
        {
            m=min(m,end[i]-start[i]+1);
        }
        
        return m;
    }
};