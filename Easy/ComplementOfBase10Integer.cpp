class Solution 
{
    public:
    int bitwiseComplement(int N) 
    {
        if (N==0)
        {
            return 1;
        }
        typedef long long int ll;
        N=(ll)N;
        ll nob=(ll)(floor(log2(N))+(ll)1);
        return (ll)((ll)(1<<nob)-(ll)1)^N;    
    }
};