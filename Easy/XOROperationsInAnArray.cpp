class Solution 
{
    public:
    int xorOperation(int n, int start) 
    {
        int XOR=start;
        for (int i=1;i<n;i++)
        {
            XOR=XOR^(start+2*i);
        }
        return XOR;
    }
};