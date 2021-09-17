class Solution 
{
    public:
    int minFlipsMonoIncr(string s) 
    {
        //At each index in the string check the cost of making a string like 0 till i and 1 after it. Find the minimum cost.
        //Edge Case: Also consider when whole string can become 1 or can become 0 at a lesser cost
        int N=s.size();
        int count0=0,count1=0,minVal=INT_MAX,total0=0;
        for (int i=0;i<N;i++)
        {
            if (s[i]=='0')
            {
                total0++;
            }
        }
        for (int i=0;i<N;i++)
        {
            if (s[i]=='0')
            {
                count0++;
            }
            else
            {
                count1++;
            }
            minVal=min(minVal,count1+total0-count0);
        }
        minVal=min(minVal,total0);
        minVal=min(minVal,N-total0);
        return minVal;
    }
};