class Solution 
{
    public:
    
    bool helper(int mid,vector<int> &position,int m)
    {
        int count=1,pos=position[0];
        for (int i=1;i<position.size();i++)
        {
            if(position[i]-pos>=mid)
            {
                pos=position[i];
                count++;
                if (count==m)
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) 
    {
        int n=position.size();
        sort(position.begin(),position.end());
        int l=0;
        int r=position[n-1],mid,max=-1;
        while(l<r)
        {
            mid=l+(r-l)/2;
            if (helper(mid,position,m)==true)
            {
                if (mid>max)
                {
                    max=mid;
                }
                l=mid+1;
            }
            else 
            {
                r=mid;
            }
        }
        return max;
    }
    
};