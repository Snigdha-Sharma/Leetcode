class Solution 
{
    public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) 
    {
        if (r*c==nums.size()*nums[0].size())
        {
            vector<vector<int> > ans;
            vector<int> temp;
            for (int i=0;i<c;i++)
            {
                temp.push_back(0);
            }
            for (int i=0;i<r;i++)
            {
                ans.push_back(temp);
            }
            int a=0,b=0;
            for (int i=0;i<nums.size();i++)
            {
                for (int j=0;j<nums[0].size();j++)
                {
                    if (b<c)
                    {
                        ans[a][b]=nums[i][j];
                        b++;
                    }
                    if (b==c)
                    {
                        a++;
                        b=0;
                    }
                }
            }
            return ans;
        }
        else
        {
            return nums;
        }
    }
};