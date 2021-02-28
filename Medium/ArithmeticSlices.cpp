class Solution 
{
    public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        if(A.size()<=2)
        {
            return 0;
        }
        vector<int> diff;
        for(int i=1;i<A.size();i++)
        {
            diff.push_back(A[i]-A[i-1]);
        }
        int start=diff[0],count=1,ans=0;
        for(int i=1;i<diff.size();i++)
        {
            if(diff[i]==start)
            {
                count++;
            }
            else
            {
                if(count>=2)
                {
                    ans=ans+((count*(count-1))/2);
                }
                start=diff[i];
                count=1;
            }
        }
        if(count>=2)
        {
            ans=ans+((count*(count-1))/2);
        }
        return ans;
    }
};