class Solution 
{
    public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int> > ans;
        vector <int> row;
        for (int line=1;line<=numRows;line++)
        {
            long int C=1;
            for (int i=1;i<=line;i++)
            {
                row.push_back(C);
                C=(C*(line-i))/i;
            }
            ans.push_back(row);
            row.clear();
        }
        return ans;
    }
};