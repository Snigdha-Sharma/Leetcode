class Solution 
{
    public:
    int countSubstrings(string s, string t) 
    {
        //Since substrings are considered in the question we have and advantage of the continuous property. So if one difference has occured then you can stop considering
        // that path when another difference comes. Now since substrings in both strings can start from any index so we will have to consider all index pairs
        int S=s.size(),T=t.size(),ans=0;
        for (int i=0;i<S;i++)
        {
            for (int j=0;j<T;j++)
            {
                int x=i,y=j,diff=0;
                while(x<S && y<T && diff<2)
                {
                    if (s[x]!=t[y])
                    {
                        diff++;
                    }
                    if (diff==1)
                    {
                        ans++;
                    }
                    x++;
                    y++;
                }
            }
        }
        return ans;
    }
};