class Solution 
{
    public:
    int maxNumberOfBalloons(string text) 
    {
        vector<float> freq;
        for (int i=0;i<5;i++)
        {
            freq.push_back(0);
        }
        for (int i=0;i<text.size();i++)
        {
            if (text[i]=='b')
            {
                freq[0]++;
            }
            else if (text[i]=='a')
            {
                freq[1]++;
            }
            else if (text[i]=='l')
            {
                freq[2]++;
            }
            else if (text[i]=='o')
            {
                freq[3]++;
            }
            else if (text[i]=='n')
            {
                freq[4]++;
            }
        }
        int ans=INT_MAX;
        freq[2]=freq[2]/2;
        freq[3]=freq[3]/2;
        for (int i=0;i<5;i++)
        {
            ans=min((int)freq[i],ans);
        }
        return ans;
    }
};