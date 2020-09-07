class Solution 
{
    public:
    string toGoatLatin(string S) 
    {
        vector<string> tokens;
        stringstream check1(S);
        string intermediate;
        while(getline(check1,intermediate,' '))
        {
            tokens.push_back(intermediate);
        }
        for (int i=0;i<tokens.size();i++)
        {
            if (tokens[i][0]=='a' || tokens[i][0]=='e' || tokens[i][0]=='i' || tokens[i][0]=='o' || tokens[i][0]=='u' || tokens[i][0]=='A' || tokens[i][0]=='E' || tokens[i][0]=='I' || tokens[i][0]=='O' || tokens[i][0]=='U')
            {
                tokens[i]=tokens[i]+"ma";
            }
            else
            {
                string k=tokens[i].substr(1,tokens[i].size());
                k=k+tokens[i][0];
                k=k+"ma";
                tokens[i]=k;
            }
            for (int j=0;j<=i;j++)
            {
                tokens[i]=tokens[i]+'a';
            }
        }
        string ans="";
        for (int i=0;i<tokens.size();i++)
        {
            ans=ans+tokens[i]+" ";
        }
        return ans.substr(0,ans.size()-1);
    }
};