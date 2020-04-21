class Solution 
{
    public:
    
    int kadane (vector<int> arr)
    {
        int curr_max=arr[0];
        int max_so_far=arr[0];
        for (int i=1;i<arr.size();i++)
        {
            curr_max=max(arr[i],curr_max+arr[i]);
            max_so_far=max(max_so_far,curr_max);
        }
        return max_so_far;
    }
    
    int maxSubarraySumCircular(vector<int>& A) 
    {
        int mex=INT_MIN;
        int count=0;
        for (int i=0;i<A.size();i++)
        {
            if (A[i]<0)
            {
                count++;
                mex=max(mex,A[i]);
            }
        }
        if (count==A.size())
        {
            return mex;
        }
        int ans1=kadane(A);
        int totalsum=0;
        for (int i=0;i<A.size();i++)
        {
            totalsum+=A[i];
            A[i]=-A[i];
        }
        int ans2=totalsum+kadane(A);
        return max(ans1,ans2);
    }
};