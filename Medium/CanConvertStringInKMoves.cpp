class Solution 
{
    public:
    bool canConvertString(string s, string t, int k) 
    {
        if (s.size()!=t.size())
        {
            return false;
        }
        if (k==0)
        {
            if (s==t)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        vector<int> shift(s.size(),0);
        vector<int> allow(27,0);
        for (int i=0;i<s.size();i++)
        {
            shift[i]=t[i]-s[i];
            if (shift[i]<0)
            {
                shift[i]+=26;
            }
        }
        
        int mod=k%26;
        int num=k/26+1;
        for (int i=1;i<=mod;i++)
        {
            allow[i]=num;
        }
        for (int j=mod+1;j<=26;j++)
        {
            allow[j]=num-1;
        }
        
        // for (int i=0;i<shift.size();i++)
        // {
        //     cout<<shift[i]<<" ";
        // }
        // cout<<endl;
        // for (int i=1;i<=26;i++)
        // {
        //     cout<<allow[i]<<" ";
        // }
        // cout<<endl;
        
        unordered_map<int,int> umap;
        for (int i=0;i<shift.size();i++)
        {
            if (shift[i]!=0)
            {
                if (umap.find(shift[i])==umap.end())
                {
                    umap[shift[i]]=1;
                }
                else
                {
                    umap[shift[i]]++;
                }
            }
            
        }
        for (auto it=umap.begin();it!=umap.end();it++)
        {
            //cout<<it->first<<" "<<it->second<<" "<<allow[it->first]<<endl;
            if (allow[it->first]<it->second)
            {
                return false;
            }
        }
        return true;
    }
};