class Solution 
{
    public:
    
    int checkSquare(vector<int> temp,int sz)
    {
        int sum=0,ans=0;
        for (int i=0;i<sz;i++)
        {
            sum+=temp[i];
        }
        if (sum==sz*sz)
        {
            ans=1;
        }
        else
        {
            for (int i=1;i<=temp.size()-sz;i++)
            {
                sum=sum+temp[i+sz-1];
                sum=sum-temp[i-1];
                if (sum==sz*sz)
                {
                    ans=1;
                }
            }
        }
        return ans;
    }

    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if (matrix.size()==0)
        {
            return 0;
        }
        vector<int> temp;
        for (int i=0;i<matrix.size();i++)
        {
            temp.push_back(0);
        }
        int left=0,right=0,sz=1;
        int flag=0;
        for (left=0;left<matrix[0].size();left++)
        {
            for (int i=0;i<matrix.size();i++)
            {
                if (matrix[i][left]=='1')
                {
                    temp[i]=1;
                }
                else
                {
                    temp[i]=0;
                }
            }
            
            if (checkSquare(temp,1)==1)
            {
                flag=1;
                for (int i=0;i<matrix.size();i++)
                {
                    for (int j=left+1;j<left+sz && left+sz<matrix[0].size();j++)
                    {
                        if (matrix[i][j]=='1' && temp[i]!=0)
                        {
                            temp[i]++;
                        }
                        else
                        {
                            temp[i]=0;
                        }
                    }
                }
                for (right=left+sz;right<matrix[0].size();right++)
                {
                    for(int i=0;i<matrix.size();i++)
                    {
                        if (matrix[i][right]=='1' && temp[i]!=0)
                        {
                            temp[i]++;
                        }
                        else
                        {
                            temp[i]=0;
                        }
                    }
                    int ns=sz+1;
                    if (ns>temp.size())
                    {
                        break;
                    }
                    if(checkSquare(temp,ns)==0)
                    {
                        break;
                    }
                    else
                    {
                        sz++;
                    }
                }
            }
            
            if (sz>temp.size())
            {
                sz--;
                break;
            }
        }
        if (flag==0)
        {
            sz=0;
        }
        return sz*sz;
    }
};