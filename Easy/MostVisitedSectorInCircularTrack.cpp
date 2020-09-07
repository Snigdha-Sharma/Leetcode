class Solution 
{
    public:
    vector<int> mostVisited(int n, vector<int>& rounds) 
    {
        vector<int> ar(n+1,0);
        for (int i=1;i<rounds.size();i++)
        {
            int s=rounds[i-1],e=rounds[i];
            if (s<e)
            {
                for (int i=s+1;i<=e;i++)
                {
                    ar[i]++;
                }
            }
            else
            {
                for (int i=s+1;i<=n;i++)
                {
                    ar[i]++;
                }
                for (int i=1;i<=e;i++)
                {
                    ar[i]++;
                }
            }
        }
        ar[rounds[0]]++;
        for (int i=1;i<=n;i++)
        {
            cout<<ar[i]<<" ";
        }
        cout<<endl;
        vector<int> ans;
        int maxNum=INT_MIN;
        for (int i=1;i<=n;i++)
        {
            maxNum=max(maxNum,ar[i]);
        }
        for (int i=1;i<=n;i++)
        {
            if (ar[i]==maxNum)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};