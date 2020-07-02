class Solution 
{
    public:
    int minFallingPathSum(vector<vector<int>>& A) 
    {
        int n=A.size();
        int m=A[0].size();
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                int best=A[i+1][j];
                if(j>0)
                {
                    best=min(best,A[i+1][j-1]);
                }
                if(j+1<m)
                {
                    best=min(best,A[i+1][j+1]);
                }
                A[i][j]+=best;
            }
        }
        int ans=INT_MAX;
        for(auto i:A[0])
        {
            ans=min(ans,i);
        }
        return ans;
    }
};