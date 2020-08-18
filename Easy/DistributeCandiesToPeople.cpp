class Solution 
{
    public:
    vector<int> distributeCandies(int candies, int num_people) 
    {
        vector<int> res(num_people,0);
        int i=0,k=1;
        while(candies>0)
        {
            int add=min(k,candies);
            res[i%num_people]+=add;
            k++; 
            candies=candies-add;
            i++;
        }
        return res ;
    }
};