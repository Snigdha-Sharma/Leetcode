//Instead of adding everytime simply maintain a prefix sum array. Then sum can be returned in O(1) time

class NumArray 
{
    public:
    
    vector<int> prefixArr;
    NumArray(vector<int>& nums) 
    {
        int N=nums.size(),cursum=0;
        for (int i=0;i<N;i++)
        {
            cursum+=nums[i];
            prefixArr.push_back(cursum);
        }
    }
    
    int sumRange(int left, int right) 
    {
        if (left-1>=0)
        {
            return prefixArr[right]-prefixArr[left-1];
        }
        return prefixArr[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */