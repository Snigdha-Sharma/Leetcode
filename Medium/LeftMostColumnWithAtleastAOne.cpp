class Solution 
{
    public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) 
    {
        vector<int> sz;
        sz=binaryMatrix.dimensions();
        int r=sz[0];
        int c=sz[1];
        int i=0,j=c-1,flag=0;
        while(i<r && j>=0)
        {
            if ((binaryMatrix.get(i,j))==1)
            {
                flag=1;
                j--;
            }
            else
            {
                i++;
            }
        }
        j++;
        if (flag==0)
        {
            j=-1;
        }
        return j;
    }
};