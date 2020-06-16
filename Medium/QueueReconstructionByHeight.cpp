//Arrange all the person based on the heights sorted in decreasing order and if two or more person has same heights then compare their K values in assending order.
//Insert one by one based on K value in the queue
class Solution 
{
    public:
    
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if (a[0]==b[0])
        {
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int> > ans;
        list<vector<int> > l;
        auto it=l.begin();
        for (int i=0;i<people.size();i++)
        {
            it=l.begin();
            advance(it,people[i][1]);
            l.insert(it,people[i]);
        }
        for (auto i=l.begin();i!=l.end();i++)
        {
            ans.push_back(*i);
        }
        return ans;
    }
};