class Solution 
{
    public:
    
    bool checker(vector<int> v)
    {
        int n=v.size();
        for (int i=0;i<n;i++)
        {
            if (v[i]<n-i-1)
            {
                return false;
            }
        }
        return true;
    }
    
    int minSwaps(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<int> count0(n,0);
        for (int i=0;i<n;i++)
        {
            for (int j=n-1;j>=0;j--)
            {
                if(grid[i][j]==0)
                {
                    count0[i]++;
                }
                else
                {
                    break;
                }
            }
        }
        
        vector<int> d=count0;
        sort(d.begin(),d.end(),greater<int>());
        if (checker(d))
        {
            int ans=0;
            for (int i=0;i<n;i++)
            {
                if (count0[i]<n-i-1)
                {
                    int j=i;
                    for (j=i+1;j<n;j++)
                    {
                        if (count0[j]>=n-i-1)
                        {
                            break;
                        }
                    }
                    while(j!=i)
                    {
                        ans++;
                        swap(count0[j],count0[j-1]);
                        j--;
                    }
                }
            }
            return ans;
        }
        
        return -1;
    }
};