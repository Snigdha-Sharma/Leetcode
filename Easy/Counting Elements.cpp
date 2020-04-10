class Solution 
{
    public:
    int countElements(vector<int>& arr) 
    {
        int count=0;
        vector<int> freq;
        for (int i=0;i<=1000;i++)
        {
            freq.push_back(0);
        }
        for (int i=0;i<arr.size();i++)
        {
            freq[arr[i]]++;
        }
        for (int i=1;i<=1000;i++)
        {
            if (freq[i]!=0)
            {
                count=count+freq[i-1];
            }
        }
        return count;
    }
};