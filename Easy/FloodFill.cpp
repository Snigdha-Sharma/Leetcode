class Solution 
{
    public:
    
    int curr,nor,noc;
    
    void fill(vector<vector<int>>& image,int x,int y,int color)
    {
        //cout<<"x="<<x<<",y="<<y<<endl;
        if (image[x][y]!=curr || image[x][y]==color)
        {
            return;
        }
        else
        {
            image[x][y]=color;
        }
        if (x-1>=0 && image[x-1][y]==curr)
        {
            fill(image,x-1,y,color);
        }
        if (x+1<nor && image[x+1][y]==curr)
        {
            fill(image,x+1,y,color);
        }
        if (y-1>=0 && image[x][y-1]==curr)
        {
            fill(image,x,y-1,color);
        }
        if (y+1<noc && image[x][y+1]==curr)
        {
            fill(image,x,y+1,color);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        curr=image[sr][sc];
        nor=image.size();
        noc=image[0].size();
        fill(image,sr,sc,newColor);
        return image;
    }
};