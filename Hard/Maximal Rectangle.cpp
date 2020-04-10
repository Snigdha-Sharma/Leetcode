class Solution 
{
    public:
    
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if (matrix.size()==0)
        {
            return 0;
        }
        int left,right,area=0;
        vector<int> temp;
    
        for (int i=0;i<matrix.size();i++)
        {
            temp.push_back(0);
        }
        
        for (left=0;left<matrix[0].size();left++)
        {
            for (int i=0;i<temp.size();i++)
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
            
            int sn=0,snmax=0;;
            for (int i=0;i<temp.size();i++)
            {
                if (temp[i]>0)
                {
                    sn++;
                }
                else
                {
                    snmax=max(snmax,sn);
                    sn=0;
                }
            }
            snmax=max(snmax,sn);
            area=max(area,snmax);

            for (right=left+1;right<matrix[0].size();right++)
            {
                int count=0;
                for (int i=0;i<temp.size();i++)
                {
                    if (matrix[i][right]=='1' && temp[i]==(right-left))
                    {
                        temp[i]++;
                    }
                    else
                    {
                        count++;
                        temp[i]=0;
                    }
                }
                if (count==matrix.size())
                {
                    break;
                }
                
                int sn=0,snmax=0;;
                for (int i=0;i<temp.size();i++)
                {
                    if (temp[i]>0)
                    {
                        sn++;
                    }
                    else
                    {
                        snmax=max(snmax,sn);
                        sn=0;
                    }
                }
                snmax=max(snmax,sn);
                area=max(area,snmax*(right-left+1));
                
            }
        }
        return area;
    }
    
};