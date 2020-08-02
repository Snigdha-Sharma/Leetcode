class Solution 
{
    public:
    
    string addBinary(string a, string b) 
    {
        int alen=a.size(),blen=b.size();
        string ans="";
        char carry='0';
        while(alen>0 && blen>0)
        {
            alen--;
            blen--;
            if (a[alen]=='0' && b[blen]=='0' && carry=='0')
            {
                //All 3 are 0
                ans="0"+ans;
                carry='0';
            }
            else if ((a[alen]=='0' && b[blen]=='0' && carry=='1') || (a[alen]=='1' && b[blen]=='0' && carry=='0') || (a[alen]=='0' && b[blen]=='1' && carry=='0'))
            {
                //One of them is zero
                ans="1"+ans;
                carry='0';
            }
            else if ((a[alen]=='1' && b[blen]=='0' && carry=='1') || (a[alen]=='0' && b[blen]=='1' && carry=='1') || (a[alen]=='1' && b[blen]=='1' && carry=='0'))
            {
                ans="0"+ans;
                carry='1';
            }
            else if (a[alen]=='1' && b[blen]=='1' && carry=='1')
            {
                ans="1"+ans;
                carry='1';
            }
        }
        while(alen>0)
        {
            alen--;
            if (carry=='0')
            {
                ans=a[alen]+ans;
            }
            else
            {
                if (a[alen]=='1')
                {
                    ans="0"+ans;
                    carry='1';
                }
                else
                {
                    ans="1"+ans;
                    carry='0';
                }
            }
            
        }
        while(blen>0)
        {
             blen--;
            if (carry=='0')
            {
                ans=b[blen]+ans;
            }
            else
            {
                if (b[blen]=='1')
                {
                    ans="0"+ans;
                    carry='1';
                }
                else
                {
                    ans="1"+ans;
                    carry='0';
                }
            }
           
        }
        if (carry=='1')
        {
            ans="1"+ans;
        }
        return ans;
    }
};