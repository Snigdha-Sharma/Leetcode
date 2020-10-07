class Solution 
{
    public:
    string getHint(string secret, string guess) 
    {
        unordered_map<char,int> usecret,uguess;
        
        int b=0;
        for (int i=0;i<secret.size();i++)
        {
            if (secret[i]==guess[i])
            {
                b++;
            }
            else
            {
                if (usecret.find(secret[i])!=usecret.end())
                {
                    usecret[secret[i]]++;
                }
                else
                {
                    usecret[secret[i]]=1;
                }
                if (uguess.find(guess[i])!=uguess.end())
                {
                    uguess[guess[i]]++;
                }
                else
                {
                    uguess[guess[i]]=1;
                }
            }
        }
        int c=0;
        for (auto it=usecret.begin();it!=usecret.end();it++)
        {
            if (uguess.find(it->first)!=uguess.end())
            {
                c=c+min(it->second,uguess[it->first]);
            }
        }
        string ans="";
        ans=ans+to_string(b)+"A"+to_string(c)+"B";
        return ans;
    }
};