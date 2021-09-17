class Solution 
{
    public:
    
    pair<long long int,long long int> getRealAndImaginaryPartofComplexNumber(string num)
    {
        pair<long long int,long long int> ans;
        for (int i=0;i<num.size();i++)
        {
            if (num[i]=='+')
            {
                ans.first=stoll(num.substr(0,i));
                ans.second=stoll(num.substr(i+1,num.size()-2));
                return ans;
            }
        }
        return ans;
    }
    
    string complexNumberMultiply(string num1, string num2) 
    {
        long long int r1,r2,i1,i2,r,i;
        pair<long long int,long long int> A=getRealAndImaginaryPartofComplexNumber(num1), B=getRealAndImaginaryPartofComplexNumber(num2);
        r1=A.first;
        r2=B.first;
        i1=A.second;
        i2=B.second;
        //cout<<"r1="<<r1<<", i1="<<i1<<", r2="<<r2<<", i2="<<i2<<endl;
        r=r1*r2 - i1*i2;
        i=r1*i2 + r2*i1;
        return to_string(r)+"+"+to_string(i)+"i";
    }
};