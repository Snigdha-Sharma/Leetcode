class Solution 
{
    public:
    vector<vector<int>> largeGroupPositions(string S) 
    {
        char c;
        c=S[0];
        int start=0,end=0,count=1;
        vector<vector<int> > ans;
        vector<int> temp;
        for (int i=1;i<S.size();i++)
        {
            if (S[i]==S[i-1])
            {
                count++;
                end++;
            }
            else
            {
                if (count>=3)
                {
                    temp.push_back(start);
                    temp.push_back(end);
                    ans.push_back(temp);
                    temp.clear();
                }
                start=i;
                end=i;
                count=1;
            }
        }
        if (count>=3)
        {
            temp.push_back(start);
            temp.push_back(end);
            ans.push_back(temp);
        }
        return ans;
    }
};