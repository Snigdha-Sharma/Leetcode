class Solution 
{
    public:
    int findJudge(int N, vector<vector<int>>& trust) 
    {
        if (N==1)
        {
            return 1;
        }
        if (trust.size()<N-1)
        {
            return -1;
        }
        vector<int> trusted;
        vector<int> trustee;
        for (int i=0;i<N;i++)
        {
            trustee.push_back(0);
            trusted.push_back(0);
        }
        for (int i=0;i<trust.size();i++)
        {
            trustee[trust[i][0]-1]++;
            trusted[trust[i][1]-1]++;
        }
        int ans=-1;
        for (int i=0;i<N;i++)
        {
            if (trusted[i]==N-1 && trustee[i]==0)
            {
                ans=i+1;
                break;
            }
        }
        return ans;
    }
};