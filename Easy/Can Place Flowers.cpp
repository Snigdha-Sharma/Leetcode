class Solution 
{
    public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        bool flag=false;
        int i=0;
        while(i+1<flowerbed.size() && n)
        {
            if (flowerbed[i]==1)
            {
                flag=true;
            }
            else if (flowerbed[i]==0 && flowerbed[i+1]==0 && flag==false)
            {
                n--;
                flag=true;
            }
            else if (flowerbed[i]==0 && flowerbed[i+1]==0 && flag==true)
            {
                flag=false;
            }
            else if (flowerbed[i]==0 && flowerbed[i+1]==1)
            {
                flag=false;
            }
            i++;
        }
        if (flag==false && flowerbed[i]==0 && n)
        {
            n--;
        }
        if (n)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};