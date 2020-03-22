class Solution 
{
    public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.size()==0)
        {
            return "";
        }
        string ans="";
        int len=strs[0].size();
        int index=0;
        for (int i=1;i<strs.size();i++)
        {
            if(strs[i].size()<len)
            {
                len=strs[i].size();
                index=i;
            }
        }
        char comp;
        int flag=0;
        for (int i=0;i<len;i++)
        {
            flag=0;
            comp=strs[index][i];
            for (int j=0;j<strs.size();j++)
            {
                if (strs[j][i]!=comp)
                {
                    flag=1;
                    break;
                }
            }
            if (flag==1)
            {
                break;
            }
            else
            {
                ans=ans+comp;
            }
        }
        return ans;
    }
};