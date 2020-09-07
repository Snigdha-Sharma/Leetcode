//1)Update within range l to r 
//2)Then check if k has reached tlen or not Update current min length if reached
//3)if k==tlen then reduce the size ,else move r forward

class Solution 
{
    public:
    
    void showMap(unordered_map<char,int> &umap)
    {
        for (auto it=umap.begin();it!=umap.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
    }
    
    string minWindow(string s, string t) 
    {
        //umap stores the required frequency of each letter in the string t
        //umap1 is initialised here and stores real time frequency of the required characters within range [l,r]
        unordered_map<char,int> umap,umap1;
        for (int i=0;i<t.size();i++)
        {
            if (umap.find(t[i])!=umap.end())
            {
                umap[t[i]]++;
            }
            else
            {
                umap[t[i]]=1;
                umap1[t[i]]=0;
            }
        }

        string ans="";

        int l=0,r=0,len=INT_MAX,k=0,lans=-1,rans=-1,tlen=t.size();

        do
        {
            //cout<<"l="<<l<<",r="<<r<<endl;
            if (k<tlen)
            {
                if (umap.find(s[r])!=umap.end())
                {
                    umap1[s[r]]++;
                    if (umap1[s[r]]<=umap[s[r]])
                    {
                        k++;
                    }
                }
            }
            else 
            {
                if (umap.find(s[l-1])!=umap.end())
                {
                    //cout<<"S[l]="<<s[l]<<" "<<umap1[s[l]]<<endl;
                    umap1[s[l-1]]--;
                    if (umap1[s[l-1]]<umap[s[l-1]])
                    {
                        k--;
                    }
                    
                }
                
            }
            //showMap(umap1);
            
            if (k==tlen && r-l+1<len)
            {
                len=r-l+1;
                lans=l;
                rans=r;
            }
            //cout<<"len="<<len<<",k="<<k<<"lans="<<lans<<",rans="<<rans<<endl;
            if(k<tlen && r<s.size())
            {
                r++;
            }
            else
            {
                l++;
            }
        }while(l<=r);
        
        //cout<<"Lans="<<lans<<",rans="<<rans;
        if(lans==-1 && rans==-1)
        {
            return "";
        }
        for (int i=lans;i<=rans;i++)
        {
            ans=ans+s[i];
        }
        //cout<<"ans="<<ans;
        return ans;
    }
};