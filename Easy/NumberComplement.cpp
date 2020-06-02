class Solution 
{
    public:
    
    typedef long long int ll;
    
    int findComplement(int num) 
    {
        num=(ll)num;
        ll nob=(ll)(floor(log2(num))+(ll)1);
        return (ll)((ll)(1<<nob)-(ll)1)^num;
    }
};