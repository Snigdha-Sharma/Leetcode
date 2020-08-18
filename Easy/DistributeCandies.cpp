class Solution 
{
    public:
    int distributeCandies(vector<int>& candies) 
    {
        int n=candies.size()/2;
        set<int> s;
        for (int i=0;i<candies.size();i++)
        {
            s.insert(candies[i]);
        }
        if (s.size()<=n)
        {
            return s.size();
        }
        return n;
    }
};