class Solution 
{
    public:
    string intToRoman(int num) 
    {
        vector<int> nums{1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> sym{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int i=12;
        string ans;
        while(num>0)
        {
            int div=num/nums[i];
            num=num%nums[i];
            while(div--)
            {
                ans=ans+sym[i];
            }
            i--;
        }
        return ans;
    }
};