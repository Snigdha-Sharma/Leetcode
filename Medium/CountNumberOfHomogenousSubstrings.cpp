class Solution 
{
    public:
    int countHomogenous(string s) 
    {
        long int ans=0,count=1,M=1e9+7;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
            {
                count++;
            }
            else
            {
                ans=ans+(((count%M)*((count+1)%M))%M)/2;
                count=1;
            }
        }
        ans=ans+((count*(count+1))/2)%M;
        return ans%M;
    }
};