class Solution 
{
    public:
    string maximumTime(string time) 
    {
        string ans="";
        if (time[0]=='?')
        {
            if (time[1]=='?')
            {
                ans=ans+"2";
            }
            else if (time[1]>'3')
            {
                ans=ans+"1";
            }
            else
            {
                ans=ans+"2";
            }
        }
        else
        {
            ans=ans+time[0];
        }
        if (time[1]=='?')
        {
            if (time[0]=='1' || time[0]=='0')
            {
                ans=ans+"9";
            }
            else
            {
                ans=ans+"3";
            }
        }
        else
        {
            ans=ans+time[1];
        }
        ans=ans+":";
        if (time[3]=='?')
        {
            ans=ans+"5";
        }
        else
        {
            ans=ans+time[3];
        }
        
        if (time[4]=='?')
        {
            ans=ans+"9";
        }
        else
        {
            ans=ans+time[4];
        }
        
        return ans;
    }
};