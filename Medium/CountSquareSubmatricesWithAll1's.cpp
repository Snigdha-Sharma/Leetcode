class Solution 
{
    public:
    int countSquares(vector<vector<int>>& matrix) 
    {
        int n=matrix.size(),m=matrix[0].size();
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                int d=0,l=0,t=0;
                if (i-1>=0)
                {
                    t=matrix[i-1][j];
                }
                if (j-1>=0)
                {
                    l=matrix[i][j-1];
                }
                if (i-1>=0 && j-1>=0)
                {
                    d=matrix[i-1][j-1];
                }
                matrix[i][j]=t+l-d+matrix[i][j];
            }
        }
        //First store in each cell sum of all 1's in the area whose top left is at (0,0) and bottom right at current cell
        // for (int i=0;i<n;i++)
        // {
        //     for (int j=0;j<m;j++)
        //     {
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        //Then for each possible side length find each square submatrix sum. If it is equal to side length then, matrix is square and has all 1's
        int ans=0;
        for (int sz=1;sz<=min(n,m);sz++)
        { 
            for (int i=sz-1;i<n;i++)
            {
                for (int j=sz-1;j<m;j++)
                {
                    int area=0;
                    if (i-sz>=0 && j-sz>=0)
                    {
                        area=matrix[i][j]-matrix[i-sz][j]-matrix[i][j-sz]+matrix[i-sz][j-sz];
                    }
                    else if (i-sz>=0)
                    {
                        area=matrix[i][j]-matrix[i-sz][j];
                    }
                    else if (j-sz>=0)
                    {
                        area=matrix[i][j]-matrix[i][j-sz];
                    }
                    else
                    {
                        area=matrix[i][j];
                    }
                    if (area==sz*sz)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};