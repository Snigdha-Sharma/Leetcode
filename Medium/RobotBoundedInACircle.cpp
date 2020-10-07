//Very good logic

class Solution 
{
    public:
    bool isRobotBounded(string instructions) 
    {
        int x=0,y=0;
        char dir='N';
        for (int i=0;i<instructions.size();i++)
        {
            if (instructions[i]=='L')
            {
                if (dir=='N')
                {
                    dir='W';
                }
                else if (dir=='S')
                {
                    dir='E';
                }
                else if (dir=='E')
                {
                    dir='N';
                }
                else
                {
                    dir='S';
                }
            }
            else if (instructions[i]=='R')
            {
                if (dir=='N')
                {
                    dir='E';
                }
                else if (dir=='S')
                {
                    dir='W';
                }
                else if (dir=='E')
                {
                    dir='S';
                }
                else
                {
                    dir='N';
                }
            }
            else
            {
                if (dir=='N')
                {
                    y++;
                }
                else if (dir=='S')
                {
                    y--;
                }
                else if (dir=='E')
                {
                    x++;
                }
                else
                {
                    x--;
                }
            }
        }
        if ((x==0 && y==0) || (dir!='N'))
        {
            return true;
        }
        return false;
    }
};