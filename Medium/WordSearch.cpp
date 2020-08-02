//Searching if given word can be made from given word grid under certain conditions

class Solution 
{
    public:
    
    //Function to check if we are checking in range
    bool checkBounds(int i,int j,int R,int C)
    {
        if (i>=0 && i<R && j>=0 && j<C)
        {
            return true;
        }
        return false;
    }
    
    bool dfs(string word,int wordPt,vector<vector<char> > &board,int i,int j)
    {
        //If character of word and of board dont match end that call 
        if (word[wordPt]!=board[i][j])
        {
            return false;
        }

        //If you reach to end of word answer is found return true
        if (wordPt==word.size()-1)
        {
            return true;
        }

        //The character we are checking make it to something else so that we do not check it again by chance
        board[i][j]='#';

        //Increase word pointer position and keep checking similarly
        //Right character
        if (checkBounds(i,j+1,board.size(),board[0].size()))
        {
            if (dfs(word,wordPt+1,board,i,j+1))
            {
                return true;
            }
        }

        //Left character
        if (checkBounds(i,j-1,board.size(),board[0].size()))
        {
            if (dfs(word,wordPt+1,board,i,j-1))
            {
                return true;
            }
        }

        //Down character
        if (checkBounds(i+1,j,board.size(),board[0].size()))
        {
            if (dfs(word,wordPt+1,board,i+1,j))
            {
                return true;
            }
        }

        //Up character
        if (checkBounds(i-1,j,board.size(),board[0].size()))
        {
            if (dfs(word,wordPt+1,board,i-1,j))
            {
                return true;
            }
        }
        board[i][j]=word[wordPt];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        //Go to each character of board
        for (int i=0;i<board.size();i++)
        {
            for (int j=0;j<board[0].size();j++)
            {
                //If the character and first character of word match only then can we proceed
                if (board[i][j]==word[0])
                {
                    if (dfs(word,0,board,i,j))//dfs function is complete and it will return whether word can be made from this start
                    {
                        return true;
                    }
                }
            }
        }
        //False is returned if word cant be made
        return false;
    }
};