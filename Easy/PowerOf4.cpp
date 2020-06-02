class Solution 
{
//     Number should have only one set bit and that set bit should be in odd position from right.
// nums&num-1 ->it is used to check that it has only one set bit (power of 2)
// ffs(nums) -> give the position of first set bit from right(LSB).
// instead of ffs(num) we can use log2(n & -n) to get set bit position (LSB)
    public:
    bool isPowerOfFour(int num) 
    {
        return num>0 && !(num&num-1) && (ffs(num)%2==0 ? false:true);
    }
};