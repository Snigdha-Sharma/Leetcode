class Solution 
{
    public:
    int maxDistToClosest(vector<int>& seats) 
    {
        int ans=0,n=seats.size(),lastOccupied,dist=0,i=0;
        //To check if person can sit on the first seat
        while(seats[i]==0)
        {
            dist++;
            i++;
        }
        ans=max(ans,dist);
        dist=0;
        lastOccupied=i;
        i++;

        //To check for a seat between 2 seats 
        for (;i<n;i++)
        {
            if (seats[i]==1)
            {
                dist=i-lastOccupied-1;
                int x=ceil(dist/2.0);
                //cout<<"x="<<x<<endl;
                ans=max(ans,x);
                lastOccupied=i;
                dist=0;
            }
            else
            {
                dist++;
            }
        }

        //To check if person can sit on last seat
        ans=max(ans,n-1-lastOccupied);
        return ans;
    }
};