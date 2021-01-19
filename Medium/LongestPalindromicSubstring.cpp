//This solution has a time complexity of O(N^2). It is based on the concept that a substring from [i,j] will be a palindrome if s[i]==s[j] and substring[i+1,j-1] 
//is also a palindrome.

class Solution 
{
    public:
    
    void showMatrix(vector<vector<int> > &dp)
    {
        for (int i=0;i<dp.size();i++)
        {
            for (int j=0;j<dp.size();j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    string longestPalindrome(string s) 
    {
        int len=s.size();
        vector<vector<int> > dp(len,vector<int> (len,0));
        for (int i=0;i<len;i++)
        {
            dp[i][i]=1;
        }
        for (int i=0;i<len-1;i++)
        {
            if (s[i]==s[i+1])
            {
                dp[i][i+1]=1;   
            }
        }
        for (int i=len-3;i>=0;i--)
        {
            for (int j=i+2;j<len;j++)
            {
                if (s[i]==s[j] && dp[i+1][j-1]==1)
                {
                    dp[i][j]=1;
                }
            }
        }
        //showMatrix(dp);
        int ans=0,start=-1,end=-1;
        for (int i=0;i<len;i++)
        {
            for (int j=i;j<len;j++)
            {
                if (dp[i][j]==1)
                {
                    if(j-i+1>ans)
                    {
                        ans=j-i+1;
                        start=i;
                        end=j;
                    }
                }
            }
        }
        //cout<<"start="<<start<<",end="<<end<<endl;
        return s.substr(start,ans);
    }
};