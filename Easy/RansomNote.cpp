class Solution 
{
    public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        map<char,int> freq_r;
        for (int i=0;i<ransomNote.size();i++)
        {
            freq_r[ransomNote[i]]++;
        }
        
        map<char,int> freq_m;
        for (int i=0;i<magazine.size();i++)
        {
            freq_m[magazine[i]]++;
        }
        
        for (int i=0;i<ransomNote.size();i++)
        {
            if (freq_r[ransomNote[i]]>freq_m[ransomNote[i]])
            {
                return false;
            }
        }
        return true;
    }
};