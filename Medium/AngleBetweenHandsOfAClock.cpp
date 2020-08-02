class Solution 
{
    public:
    double angleClock(int hour, int minutes) 
    {
        if (hour==12)
        {
            hour=0;
        }
        double angleMinute=(double)(minutes*30)/(double)5;
        double angleHour=(hour*30)+((double)(minutes*30)/(double)60);
        double ans=abs(angleMinute-angleHour);
        return min(ans,360-ans);
    }
};