class Solution 
{
    public:
    int maxCoins(vector<int>& piles) 
    {
        priority_queue<int> pq;
        
        for (int i=0;i<piles.size();i++)
        {
            pq.push(piles[i]);
        }
        int ans=0,count=0;
        while(pq.size()>count)
        {
            pq.pop();
            ans=ans+pq.top();
            pq.pop();
            count++;
        }
        return ans;
    }
};