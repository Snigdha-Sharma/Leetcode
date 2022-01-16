class Solution 
{
    public:
    int numSplits(string s) 
    {
        //At each cell we just need to know the number of distinct chatacters encountered till there and the number of distinct character in the right part of the string
        //Maintain 2 dps for that and apply the condition
        int N=s.size(),ans=0;
        unordered_set<char> uset;
        vector<int> front(N,-1),back(N,-1);
        for (int i=0;i<N;i++)
        {
            uset.insert(s[i]);
            front[i]=uset.size();
        }
        uset.clear();
        for (int i=N-1;i>=0;i--)
        {
            uset.insert(s[i]);
            back[i]=uset.size();
        }
        for (int i=0;i<N-1;i++)
        {
            if (front[i]==back[i+1])
            {
                ans++;
            }
        }
        return ans;
    }
};