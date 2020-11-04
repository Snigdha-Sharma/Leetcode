class Solution 
{
    public:
    bool buddyStrings(string A, string B) 
    {
        if (A.size()!=B.size())
        {
            return false;
        }
        int sz=A.size(),count=0;
        vector<int> idx;
        for (int i=0;i<sz;i++)
        {
            if (A[i]!=B[i])
            {
                count++;
                idx.push_back(i);
            }
            if (count==3)
            {
                return false;
            }
        }
        if (count==0)
        {
            unordered_set<char> uset;
            for (int i=0;i<sz;i++)
            {
                if (uset.find(A[i])!=uset.end())
                {
                    return true;
                }
                else
                {
                    uset.insert(A[i]);
                }
            }
            return false;
        }
        if (count==1)
        {
            return false;
        }
        if (A[idx[0]]==B[idx[1]] && A[idx[1]]==B[idx[0]])
        {
            return true;
        }
        return false;
    }
};