class Solution 
{
    public:
    
    vector<int> sortArrayByParity(vector<int>& A) 
    {
        sort(A.begin(),A.end(),[](auto &a,auto &b)
             {
                 return a%2<b%2;
             }); 
        return A;
    }
};
class Solution 
{
    public:
    
    vector<int> sortArrayByParity(vector<int>& A) 
    {
        int l=0,r=A.size()-1;
        while(l<r)
        {
            if (A[l]%2!=0)
            {
                swap(A[l],A[r]);
                if (A[r]%2==0)
                {
                    swap(A[l],A[r]);
                }
                else
                {
                    r--;
                }
            }
            else
            {
                l++;
            }
        }
        return A;
    }
};