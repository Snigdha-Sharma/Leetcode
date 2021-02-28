class Solution 
{
    public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        unordered_map<int,priority_queue<int,vector<int>,greater<int> > > umap;
        for (int i=0;i<mat.size();i++)
        {
            for (int j=0;j<mat[0].size();j++)
            {
                umap[i-j].push(mat[i][j]);
            }
        }
        for (int i=0;i<mat.size();i++)
        {
            for (int j=0;j<mat[0].size();j++)
            {
                mat[i][j]=umap[i-j].top();
                umap[i-j].pop();
            }
        }
        return mat;
    }
};