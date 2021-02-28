class Solution 
{
    public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) 
    {
        priority_queue<int,vector<int>,greater<int> > pq;
        int r=matrix.size(),c=matrix[0].size();
        for (int i=0;i<r;i++)
        {
            for (int j=1;j<c;j++)
            {
                matrix[i][j]=matrix[i][j-1]^matrix[i][j];
            }
        }
        for (int i=0;i<c;i++)
        {
            for (int j=1;j<r;j++)
            {
                matrix[j][i]=matrix[j-1][i]^matrix[j][i];
            }
        }
        for(int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
            {
                if (pq.size()<k)
                {
                    pq.push(matrix[i][j]);
                }
                else
                {
                    if(matrix[i][j] > pq.top())
                   {
                       pq.pop();
                       pq.push(matrix[i][j]);
                   }
                }
            }
        }
        return pq.top();
    }
};