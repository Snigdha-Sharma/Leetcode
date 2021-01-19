class Solution 
{
    public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
        int N=A.size(),ans=0;
        unordered_map<int,int> umap;
        for (int i=0;i<N;i++)
        {
            for (int j=0;j<N;j++)
            {
                if (umap.find(A[i]+B[j])==umap.end())
                {
                    umap[A[i]+B[j]]=1;
                }
                else
                {
                    umap[A[i]+B[j]]++;
                }
            }
        }
        for (int i=0;i<N;i++)
        {
            for (int j=0;j<N;j++)
            {
                auto it=umap.find(-C[i]-D[j]);
                if (it!=umap.end())
                {
                    ans=ans+it->second;
                }
            }
        }
        return ans;
    }
};