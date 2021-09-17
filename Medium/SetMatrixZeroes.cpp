class Solution 
{
    public:
    
    void showMatrix(vector<vector<int> > &matrix)
    {
        for (int i=0;i<matrix.size();i++)
        {
            for (int j=0;j<matrix[0].size();j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int x=0,y=0;
        int N=matrix.size(),M=matrix[0].size();
        
        //Initially checking if the first row and column that we are going to use for remebering should themselves be zero or not in the end
        for (int i=0;i<M;i++)
        {
            if (matrix[0][i]==0)
            {
                x=1;
                break;
            }
        }
        for (int i=0;i<N;i++)
        {
            if (matrix[i][0]==0)
            {
                y=1;
                break;
            }
        }
        
        //Running through the matrix once and marking which rows and columns should be zero 
        for (int i=0;i<N;i++)
        {
            for (int j=0;j<M;j++)
            {
                if (matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        } 
        
        //showMatrix(matrix);
        
        //Making the matrix with corner (1,1) as required
        for (int i=1;i<N;i++)
        {
            for (int j=1;j<M;j++)
            {
                if (matrix[0][j]==0 || matrix[i][0]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        //Making the first row and first column also correct using information from frist step
        if (x==1)
        {
            for (int i=0;i<M;i++)
            {
                matrix[0][i]=0;
            }
        }
        if (y==1)
        {
            for (int i=0;i<N;i++)
            {
                matrix[i][0]=0;
            }
        }
        
        //Overall time complexity is O(N*N) and space omplexity is O(1)
    }
};