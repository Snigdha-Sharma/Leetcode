//Sort the array in descending order according to the length os the array. We sort in descending order so that largest words can be considered first(which can hide 
//smallest words if possible). Now just find in your answer string if you have already considered that word and use find methos in string for that.
class Solution 
{
    public:
    
    static bool compare(string a,string b)
    {
        return a.size()>b.size();
    }
    
    int minimumLengthEncoding(vector<string>& words) 
    {
        sort(words.begin(),words.end(),compare);
        string ans="";
        ans=ans+words[0]+"#";
        for(int i=1;i<words.size();i++)
        {
            int pos=ans.find(words[i]+"#");
            if(pos==-1)
            {
                ans=ans+words[i]+"#";
            }
        }
        return ans.size();
    }
};