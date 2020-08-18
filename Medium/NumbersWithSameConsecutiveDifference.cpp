class Solution 
{
    public:
    
    unordered_map<int,vector<int> > umap;
    
    void showMap(unordered_map<int,vector<int> > &umap)
    {
        for(auto it=umap.begin();it!=umap.end();it++)
        {
            cout<<it->first<<"->";
            vector<int> v=it->second;
            for (int i=0;i<v.size();i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }
    
    set<int> ans;
    int l;
    
    void helper(int n,int num, int dig)
    {
        if (n==0)
        {
            for (auto it=umap.begin();it!=umap.end();it++)
            {
                if (it->first!=0)
                {
                    num=it->first;
                    helper(n+1,num,it->first);
                }
            }
        }
        else if (n==l-1)
        {
            vector<int> v=umap[dig];
            int k=num;
            for (int i=0;i<v.size();i++)
            {
                k=num*10+v[i];
                ans.insert(k);
            }
        } 
        else
        {
            vector<int> v=umap[dig];
            int k=num;
            for (int i=0;i<v.size();i++)
            {
                k=num*10+v[i];
                helper(n+1,k,v[i]);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int K) 
    {
        l=N;
        vector<int> answer;
        for (int i=0;i<=9;i++)
        {
            if (i+K>=0 && i+K<=9)
            {
                umap[i].push_back(i+K);
            }
            if (i-K>=0 && i-K<=9)
            {
                umap[i].push_back(i-K);
            }
        }
        //showMap(umap);
        if (l==1)
        {
            vector<int> ans;
            for (int i=0;i<=9;i++)
            {
                ans.push_back(i);
            }
            return ans;
        }
        helper(0,0,-1);
        for (auto it=ans.begin();it!=ans.end();it++)
        {
            answer.push_back(*it);
        }
        return answer;
    }
};