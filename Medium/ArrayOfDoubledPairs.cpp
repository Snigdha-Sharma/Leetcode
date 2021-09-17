class Solution 
{
    public:
    bool canReorderDoubled(vector<int>& arr) 
    {
        //Simply find frequency of each element. Then sort the array and start with the smallest. Find its double. Decrement their frequency. 
        //If in the end any element is left then return false. Else true
        int N=arr.size();
        unordered_map<int,int> freq;
        for (int i=0;i<N;i++)
        {
            if (freq.find(arr[i])!=freq.end())
            {
                freq[arr[i]]++;
            }
            else
            {
                freq[arr[i]]=1;
            }
        }
        sort(arr.begin(),arr.end());
        for (int i=0;i<N;i++)
        {
            if (freq[arr[i]] && freq[2*arr[i]])
            {
                freq[arr[i]]--;
                freq[2*arr[i]]--;
            }
        }
        for (auto it=freq.begin();it!=freq.end();it++)
        {
            if (it->second!=0)
            {
                return false;
            }
        }
        return true;
    }
};