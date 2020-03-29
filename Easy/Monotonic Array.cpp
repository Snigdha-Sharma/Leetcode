class Solution 
{
    public:
    bool isMonotonic(vector<int>& A) 
    {
        if (A.size()==0 || A.size()==1)
        {
            return true;
        }
        bool ans=true;
        int i=0;
        for (i=1;i<A.size();i++)
        {
            if (A[i]<A[i-1])
            {
                ans=false;
                break;
            }
        }
        if (i!=A.size())
        {
            ans=true;
            for (int i=1;i<A.size();i++)
            {
                if (A[i]>A[i-1])
                {
                    ans=false;
                    break;
                }
            }
        }
        return ans;
    }
};