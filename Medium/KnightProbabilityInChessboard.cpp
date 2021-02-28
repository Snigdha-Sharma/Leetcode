class Solution 
{
    public:
    
    void showDP(vector<vector<int> > &mat)
    {
        for (int i=0;i<mat.size();i++)
        {
            for (int j=0;j<mat[0].size();j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    
    double knightProbability(int N, int K, int r, int c) 
    {
        vector<vector<double> > mat(N,vector<double> (N,0));
        mat[r][c]=1;
        vector<pair<int,int> > dir={{1,2},{2,1},{-1,2},{-2,1},{-1,-2},{-2,-1},{1,-2},{2,-1}};
        for (int l=0;l<K;l++)
        {
            vector<vector<double> > dp(N,vector<double> (N,0));
            for (int i=0;i<N;i++)
            {
                for (int j=0;j<N;j++)
                {
                    if (mat[i][j]>0)
                    {
                        for (int d=0;d<8;d++)
                        {
                            int r=i+dir[d].first;
                            int c=j+dir[d].second;
                            if (r>=0 && c>=0 && r<N && c<N)
                            {
                                dp[r][c]+=mat[i][j]/8.0;
                            }
                        }
                    }
                }
            }
            for (int i=0;i<N;i++)
            {
                for (int j=0;j<N;j++)
                {
                    mat[i][j]=dp[i][j];
                }
            }
        }
        double ans=0.0;
        for (int i=0;i<N;i++)
        {
            for (int j=0;j<N;j++)
            {
                ans=ans+mat[i][j];
            }
        }
        return ans;
    }
};