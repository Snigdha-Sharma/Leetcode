//TC:O(NlogN)
//Used caterpillar method,sorting
//Be specific about what you think
class Solution 
{
    public:
    
    void show(vector<vector<long long int> > &v)
    {
        for (int i=0;i<v.size();i++)
        {
            cout<<v[i][0]<<" "<<v[i][1]<<endl;
        }
    }
    
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        int n=nums.size();
        if (n<=1)
        {
            return false;
        }
        vector<vector<long long int> > v(n,vector<long long int> (2,0));
        for (int i=0;i<nums.size();i++)
        {
            v[i][0]=nums[i];
            v[i][1]=i;
        }
        sort(v.begin(),v.end());
        //show(v);
        int l=0,r=1;
        long long int diff=llabs(v[1][0]-v[0][0]);
        while(l<r)
        {
            //cout<<"l="<<l<<",r="<<r<<",diff="<<diff<<endl;
            if (diff<=t)
            {
                if (llabs(v[r][1]-v[l][1])<=k)
                {
                    return true;
                }
                if (r<n-1)
                {
                    r++;
                }
                else
                {
                    l++;
                }
            }
            else
            {
                l++;
                if (l==r)
                {
                    if (r<n-1)
                    {
                        r++;
                    }
                }
            }
            diff=llabs(v[r][0]-v[l][0]);
        }
        return false;
    }
};