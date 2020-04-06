class Solution 
{
    public:
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) 
    {
        vector<vector<int> > ans;
        vector<int> temp;
        for (int i=0;i<M[0].size();i++)
        {
            temp.push_back(0);
        }
        for (int i=0;i<M.size();i++)
        {
            ans.push_back(temp);
        }
        for (int i=0;i<M.size();i++)
        {
            for (int j=0;j<M[0].size();j++)
            {
                int avg=M[i][j];
                int total=1;
                if (i-1>=0 && j-1>=0)
                {
                    avg=avg+M[i-1][j-1];
                    total++;
                }
                if (i-1>=0)
                {
                    avg=avg+M[i-1][j];
                    total++;
                }
                if (i-1>=0 && j+1<M[0].size())
                {
                    avg=avg+M[i-1][j+1];
                    total++;
                }
                if (j-1>=0)
                {
                    avg=avg+M[i][j-1];
                    total++;
                }
                if (j+1<M[0].size())
                {
                    avg=avg+M[i][j+1];
                    total++;
                }
                if (i+1<M.size() && j-1>=0)
                {
                    avg=avg+M[i+1][j-1];
                    total++;
                }
                if (i+1<M.size())
                {
                    avg=avg+M[i+1][j];
                    total++;
                }
                if (i+1<M.size() && j+1<M[0].size())
                {
                    avg=avg+M[i+1][j+1];
                    total++;
                }
                avg=avg/total;
                ans[i][j]=floor(avg);
            }
        }
        return ans;
    }
};