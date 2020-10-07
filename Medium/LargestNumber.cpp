//Basically the question was about sorting but in a different manner. So apply that manner to the special input for sort function

class Solution 
{
    public:
    
    bool static style(int &n1,int &n2)
    {
        string num1=to_string(n1),num2=to_string(n2),ans1,ans2;
        ans1=num1+num2;
        ans2=num2+num1;
        long long int N1=stoll(ans1),N2=stoll(ans2);
        return N1>N2;
    }
    
    string largestNumber(vector<int>& nums) 
    {
        string ans="";
        int n=nums.size(),count0=0;
        for (int i=0;i<n;i++)
        {
            if (nums[i]!=0)
            {
                break;
            }
            else
            {
                count0++;
            }
        }
        if (count0==n)
        {
            return "0";
        }
        sort(nums.begin(),nums.end(),style);
        for (int i=0;i<n;i++)
        {
            ans=ans+to_string(nums[i]);
        }
        return ans;
    }
};