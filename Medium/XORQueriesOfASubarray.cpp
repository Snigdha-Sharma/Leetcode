//Finding XOR is essentially knowing the count of 1's on each bit in a 32 bit integer. Use this to preprocess the array.
// At every point know the count of 1's
class Solution 
{
    public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        vector<vector<int> > pre(32,vector<int> (arr.size(),0));
        vector<int> ans;
        for (int i=0;i<32;i++)
        {
            pre[i][0]=0;
            for (int j=0;j<arr.size();j++)
            {
                if (j>0)
                {
                    pre[i][j]=pre[i][j-1];
                }
                if (arr[j]&(1<<i))
                {
                    pre[i][j]++;
                }
            }
        }
        
        for (int j=0;j<queries.size();j++)
        {
            int a=0,cnt=0;
            for (int i=0;i<32;i++)
            {
                cnt=pre[i][queries[j][1]]-((queries[j][0]>0)?(pre[i][queries[j][0]-1]):0);
                if (cnt&1)
                {
                    a=a+(1<<i);
                }
            }
            
            ans.push_back(a);
        }
        
        return ans;
    }
};