class Solution 
{
    public:
    
    int numTeams(vector<int>& rating) 
    {
        int N=rating.size(),ans=0;
        //If each element knows the number of elements which are smaller than it and come after it then if you ask that element wrt another element which is greater 
        //than it you will be able to count the number of triplets in descending order. Similalrly for ascending order, each element must know number of elemenets 
        //greater than it in its front so whenever an element which comes behind it and is smaller than it asks that element we can get to know the number of triplets.
        vector<int> smaller(N,0),larger(N,0);
        for (int i=N-1;i>=0;i--)
        {
            for (int j=i+1;j<N;j++)
            {
                if (rating[j]>rating[i])
                {
                    larger[i]++;
                    ans=ans+larger[j];
                }
                else
                {
                    smaller[i]++;
                    ans=ans+smaller[j];
                }
            }
        }
        return ans;
    }
};