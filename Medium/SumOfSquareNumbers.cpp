class Solution 
{
    public:
    bool judgeSquareSum(int c) 
    {
        //You can check only till less than equal to square root of that number, store the values in a set and keep on checking if the other square pair exists
        unordered_set<long int> uset;
        for (long int i=0;i*i<=c;i++)
        {
            uset.insert(i*i);
            if (uset.find(c-i*i)!=uset.end())
            {
                return true;
            }
        }
        return false;
    }
};