class Solution 
{
    public:
    
    bool validateRowCol(vector<char> &v)
    {
        set<char> s;
        for (int i=0;i<9;i++)
        {
            if (v[i]=='.')
            {
                continue;
            }
            if(s.find(v[i])==s.end())
            {
                s.insert(v[i]);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    
    bool validateSquare(vector<vector<char>> &v,int i,int j)
    {
        set<char> s;
        for (int a=i;a<i+3;a++)
        {
            for (int b=j;b<j+3;b++)
            {
                if (v[a][b]=='.')
                {
                    continue;
                }
                if (s.find(v[a][b])==s.end())
                {
                    s.insert(v[a][b]);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for (int i=0;i<9;i++)
        {
            if (validateRowCol(board[i])==false)
            {
                //cout<<"Row failure\n";
                return false;
            }
        }
        for(int i=0;i<9;i++)
        {
            vector<char> temp;
            for (int j=0;j<9;j++)
            {
                temp.push_back(board[j][i]);
            }
            if (validateRowCol(temp)==false)
            {
                //cout<<"Column Failure\n";
                return false;
            }
        }
        for (int i=0;i<9;i=i+3)
        {
            for (int j=0;j<9;j+=3)
            {
                if (validateSquare(board,i,j)==false)
                {
                    //cout<<"Square Failure\n";
                    return false;
                }
            }
        }
        return true;
    }
};