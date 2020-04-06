class Solution 
{
    public:
    int oddCells(int n, int m, vector<vector<int>>& indices) 
    {
        vector<vector<int> > matrix;
        vector<int> temp;
        for (int i=0;i<m;i++)
        {
            temp.push_back(0);
        }
        for (int i=0;i<n;i++)
        {
            matrix.push_back(temp);
        }
        for (int i=0;i<indices.size();i++)
        {
            int r=indices[i][0];
            int c=indices[i][1];
            for (int i=0;i<m;i++)
            {
                matrix[r][i]++;
            }
            for (int i=0;i<n;i++)
            {
                matrix[i][c]++;
            }
        }
        int ans=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (matrix[i][j]%2==1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};