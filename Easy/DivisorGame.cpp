class Solution 
{
    public:
    bool divisorGame(int n) 
    {
        // A odd number can only have odd divisors. On subtracting odd from odd you can only get a even number and whoever has the first chance when given an even 
        //number wins. An even number has all even divisors except 1. You dont want to give the other player an even number to start so you subtract 1 and give him an 
        //odd number to play optimally.
        if (n%2==1)
        {
            return false;
        }
        return true;
    }
};