class Solution 
{
    public:
    string stringShift(string s, vector<vector<int>>& shift) 
    {
        int netRightShift=0,netLeftShift=0,netShift=0;
        for (int i=0;i<shift.size();i++)
        {
            if (shift[i][0]==0)
            {
                netLeftShift+=shift[i][1];
            }
            else
            {
                netRightShift+=shift[i][1];
            }
        }
        netRightShift=netRightShift%s.size();
        netLeftShift=netLeftShift%s.size();
        if (netLeftShift>netRightShift)
        {
            netShift=netLeftShift-netRightShift;
            rotate(s.begin(),s.begin()+netShift,s.end());
        }
        else
        {
            netShift=netRightShift-netLeftShift;
            rotate(s.begin(),s.begin()+s.size()-netShift,s.end());
        }
        return s;
    }
};