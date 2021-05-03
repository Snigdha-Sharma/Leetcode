class Solution 
{
    public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int ans=INT_MAX,r=triangle.size();
        for(int i=1;i<triangle.size();i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(i!=j && j!=0)
                {
                    triangle[i][j]+=min(triangle[i-1][j],triangle[i-1][j-1]);
                }
                else if (j==0)
                {
                     triangle[i][j]+=triangle[i-1][j];   
                }
                else
                {
                    triangle[i][j]+=triangle[i-1][j-1];
                }
            }
        }
        
        for(int i=0;i<r;i++)
        {
            //cout<<triangle[r-1][i]<<" ";
            ans=min(ans,triangle[r-1][i]);
        }
        return ans;
    }
};