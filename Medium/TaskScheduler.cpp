class Solution 
{
    public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> freq(26,0);
        for (int i=0;i<tasks.size();i++)
        {
            //cout<<tasks[i]<<" ";
            freq[tasks[i]-'A']++;
        }
        int maxcnt=0,e=0;
        for (int i=0;i<26;i++)
        {
            //cout<<freq[i]<<" ";
            maxcnt=max(maxcnt,freq[i]);
        }
        for (int i=0;i<26;i++)
        {
            if (freq[i]==maxcnt)
            {
                e++;
            }
        }
        int sz=tasks.size();
        int ans=max(sz,(((maxcnt-1)*(n+1))+e));
        return ans;
    }
};