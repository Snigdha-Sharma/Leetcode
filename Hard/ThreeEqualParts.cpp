class Solution 
{
    public:
    
    vector<int> threeEqualParts(vector<int>& arr) 
    {
        int N=arr.size();
        vector<int> helper;
        for (int i=0;i<N;i++)
        {
            if (arr[i]==1)
            {
                helper.push_back(i);
            }
        }
        vector<int> ans(2,-1);
        int sz=helper.size();
        if (sz==0)
        {
            ans[0]=0;
            ans[1]=N-1;
            return ans;
        }
        if (sz%3==0)
        {
            int i1=helper[0],j1=helper[sz/3-1],i2=helper[sz/3],j2=helper[(2*sz/3)-1],i3=helper[(2*sz)/3],j3=helper[sz-1];
            int z=N-j3-1;
            j1=j1+z;
            j2=j2+z;
            ans[0]=j1;
            ans[1]=j2+1;
            //cout<<"i1="<<i1<<",j1="<<j1<<",i2="<<i2<<",j2="<<",i3="<<i3<<",j3="<<j3<<endl;
            for (int num1=i1,num2=i2,num3=i3;num1<=j1;num1++,num2++,num3++)
            {
                if (arr[num1]!=arr[num2] || arr[num2]!=arr[num3])
                {
                    ans[0]=-1;
                    ans[1]=-1;
                    break;
                }
            }
        }
        return ans;
    }
};