class Solution 
{
    public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<vector<int> > ans;
        int n=mat.size(),m=mat[0].size();
        for (int i=0;i<n;i++)
        {
            int sum=0;
            for (int j=0;j<m;j++)
            {
                if (mat[i][j]==0)
                {
                    break;
                }
                else
                {
                    sum=sum+1;
                }
            }
            vector<int> temp;
            temp.push_back(sum);
            temp.push_back(i);
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        vector<int> a;
        //cout<<ans.size();
        for (int i=0;i<ans.size() && i<k;i++)
        {
            a.push_back(ans[i][1]);
        }
        return a;
    }
};