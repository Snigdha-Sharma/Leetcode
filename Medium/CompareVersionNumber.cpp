class Solution 
{
    public:
    
    void show(vector<int> x)
    {
        for (int i=0;i<x.size();i++)
        {
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    
    int compareVersion(string version1, string version2) 
    {
        vector<int> tokens1,tokens2;
        stringstream check1(version1);
        string intermediate;
        while(getline(check1,intermediate,'.'))
        {
            tokens1.push_back(stoi(intermediate));
        }
        stringstream check2(version2);
        while(getline(check2,intermediate,'.'))
        {
            tokens2.push_back(stoi(intermediate));
        }
        //show(tokens1);
        //show(tokens2);
        int i=0,j=0;
        while(i<tokens1.size() && j<tokens2.size())
        {
            if (tokens1[i]<tokens2[j])
            {
                return -1;
            }
            else if (tokens1[i]>tokens2[j])
            {
                return 1;
            }
            else
            {
                i++;
                j++;
            }
        }
        while(i<tokens1.size())
        {
            if (tokens1[i]!=0)
            {
                return 1;
            }
            i++;
        }
        while(j<tokens2.size())
        {
            if (tokens2[j]!=0)
            {
                return -1;
            }
            j++;
        }
        return 0;
    }
};