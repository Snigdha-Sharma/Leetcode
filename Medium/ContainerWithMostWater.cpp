//You need to find the rectangle whose area is maximum. We expect the largest widht rectangle to have the most area but it may be limited by the smaller of the 2 heights.
//So starting from outside keep on removing the smaller height and finding the area. Use 2 pointer approach.

class Solution 
{
    public:
    int maxArea(vector<int>& height) 
    {
        int l=0,r=height.size()-1,ans=0;
        while(l<r)
        {
            ans=max(ans,(min(height[l],height[r])*(r-l)));
            if(height[l]<height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};