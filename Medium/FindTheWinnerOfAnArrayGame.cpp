class Solution 
{
    public:
    int getWinner(vector<int>& arr, int k) 
    {
        int n=arr.size(),ans=0;
        if (k>=n-1)
        {
            for (int i=0;i<n;i++)
            {
                ans=max(ans,arr[i]);
            }
        }
        else
        {
            list<int> l;
            for (int i=0;i<n;i++)
            {
                l.push_back(arr[i]);
            }
            int el1=0,el2=0,winner=-1,freq=0;
            for (int i=0;i<n-1;i++)
            {
                el1=l.front();
                l.pop_front();
                el2=l.front();
                if (el1>el2)
                {
                    if (el1==winner)
                    {
                        freq++;
                    }
                    else
                    {
                        winner=el1;
                        freq=1;
                    }
                    l.pop_front();
                    l.push_front(el1);
                    l.push_back(el2);
                }
                else
                {
                    if (el2==winner)
                    {
                        freq++;
                    }
                    else
                    {
                        winner=el2;
                        freq=1;
                    }
                    l.push_back(el1);
                }
                if (freq==k)
                {
                    ans=winner;
                    break;
                }
            }
            if (freq<k)
            {
                ans=0;
                for (int i=0;i<n;i++)
                {
                    ans=max(ans,arr[i]);
                }
            }
        }
        return ans;
    }
};