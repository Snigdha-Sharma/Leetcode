//This solution is in O(N)
//Better solution is Binary Search:O(log N)
class Solution 
{
    public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int arp=0,ans=1,count=0;
        while(count<k)
        {
            if (arp<arr.size() && arr[arp]==ans)
            {
                arp++;
            }
            else
            {
                count++;
            }
            ans++;
        }
        return ans-1;
    }
};