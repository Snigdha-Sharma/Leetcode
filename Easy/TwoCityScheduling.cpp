//Good question

class Solution 
{
    public:
    
    static bool sortbydesc(const pair<int,int> &a,const pair<int,int> &b)
    {
        return (a.first>b.first);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        int N=costs.size()/2;
        vector<pair<int,int> > diff;
        for (int i=0;i<costs.size();i++)
        {
            diff.push_back(make_pair(abs(costs[i][0]-costs[i][1]),i));
        }
        
        // for (int i=0;i<diff.size();i++)
        // {
        //     cout<<diff[i].first<<" ";
        // }
        // cout<<endl;
        
        sort(diff.begin(), diff.end(), sortbydesc);
        int ans=0,a=0,b=0;
        for (int i=0;i<diff.size();i++)
        {
            int idx=diff[i].second;
            if (a<N && costs[idx][0]<costs[idx][1])
            {
                ans+=costs[idx][0];
                a++;
            }
            else if (a>=N)
            {
                ans+=costs[idx][1];
                b++;
            }
            else if (b<N && costs[idx][0]>costs[idx][1])
            {
                ans+=costs[idx][1];
                b++;
            }
            else if (b>=N)
            {
                ans+=costs[idx][0];
                a++;
            }
        }
        return ans;
    }
};