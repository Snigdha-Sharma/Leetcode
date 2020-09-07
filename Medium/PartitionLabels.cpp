class Solution 
{   
    public:
    
    void show(vector<vector<int> > &v)
    {
        for (int i=0;i<v.size();i++)
        {
            cout<<v[i][0]<<" "<<v[i][1]<<endl;
        }
    }
    
    vector<int> partitionLabels(string S) 
    {
        vector<int> ans;
        if (S.size()==0)
        {
            return ans;
        }
        vector<vector<int> > idx(26,vector<int>(2,-1));
        for (int i=0;i<S.size();i++)
        {
            if (idx[S[i]-'a'][0]==-1)
            {
                idx[S[i]-'a'][0]=i;
                idx[S[i]-'a'][1]=i;
            }
            else
            {
                idx[S[i]-'a'][1]=i;
            }
        }
        sort(idx.begin(),idx.end());
        
        vector<vector<int> > p;
        int i=0;
        while(i<26 && idx[i][0]==-1 && idx[i][1]==-1)
        {
            i++;
        }
        vector<int> k(2,-1);
        k[0]=idx[i][0];
        k[1]=idx[i][1];
        i++;
        for ( ;i<26;i++)
        {
            if (idx[i][0]>k[0] && idx[i][0]<k[1] && idx[i][1]>k[0] && idx[i][1]<k[1])
            {
                continue;
            }
            else if (idx[i][0]<k[1] && idx[i][1]>k[1])
            {
                k[1]=idx[i][1];
            }
            else
            {
                p.push_back(k);
                k[0]=idx[i][0];
                k[1]=idx[i][1];
            }
        }
        p.push_back(k);
        for (int i=0;i<p.size();i++)
        {
            ans.push_back(p[i][1]-p[i][0]+1);
        }
        //show(p);
        return ans;
    }
};