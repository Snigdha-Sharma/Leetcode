class Solution 
{
    public:
    
    vector<int> sum;
    
    Solution(vector<int>& w) 
    {
        for (int i=1;i<w.size();i++)
        {
            w[i]+=w[i-1];
        }
        sum=w;
        srand(time(NULL)); 
    }
    
    int findCeil(vector<int> arr,int r,int l,int h)  
    {  
        int mid;  
        while (l < h)  
        {  
            mid = l + ((h - l) >> 1); 
            (r > arr[mid]) ? (l = mid + 1) : (h = mid);  
        }  
        return (arr[l] >= r) ? l : -1;  
    } 
    
    int pickIndex() 
    {
        int num=(rand()%(sum[sum.size()-1]))+1;
        int indexc = findCeil(sum,num,0,sum.size()-1);  
        return indexc;  
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */