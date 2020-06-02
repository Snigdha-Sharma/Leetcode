class Solution 
{
    //Max number that is power of 3 and that fits into int upper limit is 3**19 (aka 1162261467).
    //This number 3**19 is divisible by any number that is <= and is power of 3.
    public:
    bool isPowerOfThree(int n) 
    {
        return n > 0 && !(1162261467 % n);
    }
};