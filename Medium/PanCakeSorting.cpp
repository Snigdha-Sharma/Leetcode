class Solution 
{
    public:
    
    void reverse(vector<int> &A,int k)
    {
        for (int i=0,j=k;i<j;i++,j--)
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    
    vector<int> pancakeSort(vector<int>& A) 
    {
        vector<int> ans;
        int largest=A.size();
        while(largest)
        {
            for (int i=0;i<A.size();i++)
            {
                if (A[i]==largest)
                {
                    if (i+1!=largest)
                    {
                        ans.push_back(i+1);
                        reverse(A,i);
                        ans.push_back(largest);
                        reverse(A,largest-1);
                    }
                    largest--;
                    break;
                }
            }
        }
        return ans;
    }
};