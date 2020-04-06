class Solution 
{
    public:
    
    bool checkZero(int x)
    {
        string h=to_string(x);
        for (int i=0;i<h.size();i++)
        {
            if (h[i]=='0')
            {
                return false;
            }
        }
        return true;
    }
    
    vector<int> getNoZeroIntegers(int n) 
    {
        vector<int> ans;
        for (int i=1;i<n;i++)
        {
            if (checkZero(i) && checkZero(n-i))
            {
                ans.push_back(i);
                ans.push_back(n-i);
                break;
            }
        }
        return ans;
    }
};