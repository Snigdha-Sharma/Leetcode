class Solution 
{
    public:
    string thousandSeparator(int n) 
    {
        string ans="";
        string num=to_string(n);
        int count=0;
        for (int i=num.size()-1;i>=0;i--)
        {
            count++;
            ans=num[i]+ans;
            //cout<<"cont="<<count;
            if (count!=num.size() && count%3==0)
            {
                ans="."+ans;
            }
            
            
        }
        //cout<<endl;
        return ans;
    }
};