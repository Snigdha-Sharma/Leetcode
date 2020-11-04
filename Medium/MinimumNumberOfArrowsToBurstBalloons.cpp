class Solution 
{
    public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int n=points.size();
        if (n==0 || n==1)
        {
            return n;
        }
        sort(points.begin(),points.end());
        vector<pair<int,int> > ans;
        ans.push_back(make_pair(points[0][0],points[0][1]));
        for (int i=1;i<n;i++)
        {
            int ans_back=ans.back().second;
            int j_start=points[i][0];
            int j_end=points[i][1];
            // Case 1: Intersecting Overlapping Intervals
            if(j_start<=ans_back && j_end>ans_back)
            {
                ans.pop_back();
                ans.push_back(make_pair(j_start,ans_back));
            }
            // Case 2: Intersecting included intervals
            else if (j_start<=ans_back && j_end<=ans_back)
            {
                ans.pop_back();
                ans.push_back(make_pair(j_start,j_end));
            }
            // Case 3: Non intersecting intervals
            else 
            {
                ans.push_back(make_pair(j_start,j_end));
            }
        }
        return ans.size();
    }
};