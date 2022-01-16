class Solution 
{
    public:
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) 
    {
        int ans=0;
        unordered_set<int> forbiddenAndVisited;
        for (int i=0;i<forbidden.size();i++)
        {
            forbiddenAndVisited.insert(forbidden[i]);
        }
        queue<pair<int,int> > q;
        q.push({0,0});
        while(!q.empty())
        {
            int sz=q.size();
            for (int i=0;i<sz;i++)
            {
                pair<int,int> popped=q.front();
                q.pop();
                if (popped.first==x)
                {
                    return ans;
                }
                if (forbiddenAndVisited.find(popped.first)!=forbiddenAndVisited.end())
                {
                    continue;
                }   
                forbiddenAndVisited.insert(popped.first);
                if (popped.second==0)
                {
                    if (popped.first-b>=0)
                        q.push({popped.first-b,1});
                }
                if (popped.first+a<=2000+a+b)
                    q.push({popped.first+a,0});
            }
            ans++;
        }
        return -1;
    }
};