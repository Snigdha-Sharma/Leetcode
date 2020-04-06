class Solution 
{
    public:
    int maximum69Number (int num) 
    {
        string N=to_string(num);
        for (int i=0;i<N.size();i++)
        {
            if (N[i]=='6')
            {
                N[i]='9';
                break;
            }
        }
        return stoi(N);
    }
};