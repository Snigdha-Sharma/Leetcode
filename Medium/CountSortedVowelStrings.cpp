class Solution 
{
    public:
        
    int countVowelStrings(int n) 
    {
        vector<int> count(5,1);
        for (int i=1;i<n;i++)
        {
            long int newa=count[0],newe=count[0]+count[1],newi=count[0]+count[1]+count[2],newo=count[0]+count[1]+count[2]+count[3],newu=count[0]+count[1]+count[2]+count[3]+count[4];
            count[0]=newa;
            count[1]=newe;
            count[2]=newi;
            count[3]=newo;
            count[4]=newu;
        }
        long int ans=0;
        for (int i=0;i<5;i++)
        {
            ans=ans+count[i];
        }
        return ans;
    }
};