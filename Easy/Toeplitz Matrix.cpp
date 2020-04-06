class Solution 
{
    public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        bool ans=true;
        int M,N;
        M=matrix.size();
        N=matrix[0].size();
        for (int i=0;i<M;i++)
        {
            for (int j=0;j<N;j++)
            {
                if (i-1>=0 && j-1>=0)
                {
                    if(matrix[i-1][j-1]!=matrix[i][j])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};