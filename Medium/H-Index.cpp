class Solution 
{
    public:
    int hIndex(vector<int>& citations) 
    {
        sort(citations.begin(),citations.end());
        int cnt=0;
        for (int i=citations.size()-1; i>=0; --i) 
        {
            ++cnt;
            if (citations[i] < cnt)
            {
                return cnt-1;
            }
        }
        return cnt;
    }
};