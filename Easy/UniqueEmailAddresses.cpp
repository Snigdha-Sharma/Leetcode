class Solution 
{
    public:
    int numUniqueEmails(vector<string>& emails) 
    {
        unordered_set<string> uset;
        for (int i=0;i<emails.size();i++)
        {
            int j=0,flag=0;
            string newLocalName="";
            for (;j<emails[i].size();j++)
            {
                if (emails[i][j]=='@')
                {
                    break;
                }
                else if (emails[i][j]=='.')
                {
                    
                }
                else if (emails[i][j]=='+')
                {
                    flag=1;
                }
                else if (flag==0)
                {
                    newLocalName+=emails[i][j];
                }
            }
            if (newLocalName.size()==0)
            {
                continue;
            }
            uset.insert(newLocalName+emails[i].substr(j,emails[i].size()));
        }
        return uset.size();
    }
};