class Solution 
{
    public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) 
    {
        int temp;
        for (int i=0;i<A.size();i++)
        {
            float J=A[i].size();
            for (int j=0;j<J/2;j++)
            {
                if (A[i][j]==A[i][J-j-1])
                {
                    if (A[i][j]==0)
                    {
                        A[i][j]=1;
                        A[i][J-j-1]=1;
                    }
                    else
                    {
                        A[i][j]=0;
                        A[i][J-j-1]=0;
                    }
                }
            }
        }
        return A;
    }
};