class Solution 
{
    public:
    vector<int> shortestToChar(string s, char c) 
    {
        vector<int> b;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]==c)
            {
                b.push_back(i);
            }
        }
        vector<int>ans(s.size(),0);
        int i=0,j=0;
        for(i=0;i<s.size();i++)
        {
            if(i>b[j] && j!=b.size()-1)
            {
                j++;
            }
            if(j==0)
            {
                ans[i]=abs(b[j]-i);
            }
            else
            {
                ans[i]=min(abs(b[j]-i),abs(b[j-1]-i));   
            }
        }
        return ans;
    }
};