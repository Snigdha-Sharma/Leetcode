class Solution 
{
    public:
    int twoEggDrop(int n) 
    {
        //Row index of dp represents number of eggs which are given, Column index of dp represents number of floors
        vector<vector<int> > dp(3,vector<int> (n+1,0));
        
        //If we have 1 egg then to make sure, we will need number of floors drop because if we drop randomly and egg breaks, then we have no way of finding the correct floor again. So we start dropping from the n=1 floor and whenever it breaks that is the answer 
        for (int i=1;i<=n;i++)
        {
            dp[1][i]=i;
        }
        
        //If you have more eggs than number of floors then the answer would just be the same when eggs were less but getting an answer was possible 
        dp[2][1]=1;
        dp[1][0]=0;
        dp[2][0]=0;
        for (int i=2;i<=n;i++)
        
        {
            int ans=INT_MAX;
            for (int j=1;j<=i;j++)//Dropping egg on each floor 
            {
                ans=min(ans,1+max(dp[1][j-1],dp[2][i-j]));
                //dp[1][j-1] means that when we drop our egg from the jth floor in our i floor problem then if the egg breaks we will have to look for our answer in the floors below (i.e. j-1) with 1 egg left now
                //dp[2][i-j] means that when we drop our egg from the jth floor in our i floor problem then if the egg doesn't break then we will have to look for our answer in the floors above (i.e. i-j) with 2 eggs
                //We take max of these answers because we do have to gie a solution to the problem when that floor can be any floor i.e. we have to give the upper limit of moves whichever floor it be.
                //We take min of the answer later because we need to choose a floor to drop our egg from such that we are able to find the answer whichever floor it is
            }
            dp[2][i]=ans;
        }
        return dp[2][n];
    }
};