class Solution 
{
    public:
    int brokenCalc(int X, int Y) 
    {
        //If Y<X then the only way to make Y is by decrementing. Else try dividing Y by 2 and if not possible then make it a multiple of 2.
        int res=0;
        while (Y>X) 
        {    
            if (Y%2) 
                Y++;
            else 
                Y/=2;
            res++;
        }
        return res+X-Y;
    }
};