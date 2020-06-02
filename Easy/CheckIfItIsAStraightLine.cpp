class Solution 
{
    public:
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        if (coordinates.size()==2)
        {
            return true;
        }
        bool ans=true;
        double m=0,ms=0;
        if ((coordinates[1][0]-coordinates[0][0])!=0)
        {
            m=((double)(coordinates[1][1]-coordinates[0][1])/(double)(coordinates[1][0]-coordinates[0][0]));
        }
        //cout<<"m="<<m<<endl;
        for (int i=2;i<coordinates.size();i++)
        {
            if ((coordinates[i][0]-coordinates[0][0])!=0)
            {
            ms=((double)(coordinates[i][1]-coordinates[0][1])/(double)(coordinates[i][0]-coordinates[0][0]));
            }
            //cout<<"ms="<<ms<<endl;
            if (ms!=m)
            {
                ans=false;
                break;
            }
            ms=0;
        }
        return ans;
    }
};