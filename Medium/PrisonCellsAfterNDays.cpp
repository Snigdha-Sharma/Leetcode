//Good pattern-hashing

class Solution 
{
    public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) 
    {
        long long int n=(long long int)N;
        vector<vector<int> > s;
        vector<int> temp;
        for (int i=0;i<8;i++)
        {
            temp.push_back(0);
        }
        for (int i=0;i<14;i++)
        {
            s.push_back(temp);
        }
       
        for (int i=0;i<14;i++)
        {
            for (int j=1;j<7;j++)
            {
                if (cells[j-1]==cells[j+1])
                {
                    s[i][j]=1;
                }
            }
            for (int j=0;j<8;j++)
            {
                cells[j]=s[i][j];
            }
        }
    
        n--;
        n=n%14;
        return s[n];
    }
};