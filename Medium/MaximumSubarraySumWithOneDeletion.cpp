//Kadane with one element deletion

class Solution 
{
    public:
    
    void showArr(vector<int> &a)
    {
        for (int i=0;i<a.size();i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    
    int maximumSum(vector<int>& arr) 
    {
        //cursum makes the decision in normal kadane of whether to continue the last subarray or start a new subarray from there
        //cursum1 makes the decision of either not taking the last element and considering sum of current element + sum before last element or 
        //it takes up the value of the last subarray and not considering the current element
        int n=arr.size();
        int cursum=arr[0],cursum1=arr[0],ans=arr[0];
        for (int i=1;i<n;i++)
        {
            cursum1=max(cursum,cursum1+arr[i]);
            cursum=max(arr[i],cursum+arr[i]);
            ans=max(ans,max(cursum,cursum1));
        }
        return ans;
    }
};