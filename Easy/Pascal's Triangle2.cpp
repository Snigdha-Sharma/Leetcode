class Solution 
{
    public:
    vector<int> getRow(int rowIndex) 
    {
        long int C=1;
        int row=rowIndex+1;
        vector <int> ans;
        for (int i=1;i<=row;i++)
        {
            ans.push_back(C);
            C=(C*(row-i))/i;
        }
        return ans;
    }
};