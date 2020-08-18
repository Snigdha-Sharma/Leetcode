class Solution 
{
    public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        //Dividing the operation in 2 steps-1)Reversing the matrix columnwise 2)FInding transpose
        int i=0,j=n-1;
        while(i<j)
        {
            for (int k=0;k<n;k++)
            {
                matrix[i][k]=matrix[j][k]^matrix[i][k];
                matrix[j][k]=matrix[j][k]^matrix[i][k];
                matrix[i][k]=matrix[i][k]^matrix[j][k];
            }
            i++;
            j--;
        }
        // for (int i=0;i<n;i++)
        // {
        //     for (int j=0;j<n;j++)
        //     {
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for (int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                if (i!=j)
                {
                    matrix[i][j]=matrix[i][j]^matrix[j][i];
                    matrix[j][i]=matrix[i][j]^matrix[j][i];
                    matrix[i][j]=matrix[j][i]^matrix[i][j];
                }
            }
        }
    }
};