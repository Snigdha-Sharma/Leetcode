//This is the optimal solution. It is inplace. First get the location of all words. Then send all the words to the end of the string. Then bring them to the front 
//while adding the spaces

class Solution 
{
    public:
    string reorderSpaces(string text) 
    {
        vector<pair<int,int> > wordIdx;
        int N=text.size(),countSpaces=0;
        for (int i=0;i<N;i++)
        {
            if (text[i]==' ')
            {
                countSpaces++;
            }
            else
            {
                int start=i,end=-1;
                while(i<N && text[i]!=' ')
                {
                    i++;
                    if (text[i]==' ')
                    {
                        countSpaces++;
                        break;
                    }
                }
                end=i;    
                wordIdx.push_back({start,end});
            }
        }
//         for (int i=0;i<wordIdx.size();i++)
//         {
//             cout<<wordIdx[i].first<<" "<<wordIdx[i].second<<endl;
//         }
        
        int end=N-1;
        for (int i=wordIdx.size()-1;i>=0;i--)
        {
            int orig=end;
            for (int x=wordIdx[i].second-1;x>=wordIdx[i].first;x--)
            {
                
                text[end]=text[x];
                end--;
            }
            wordIdx[i].first=end+1;
            wordIdx[i].second=orig;
            if (end>=0)
            {
                text[end]=' ';
            }
            end--;
        }
        
        while(end>0)
        {
            text[end]=' ';
            end--;
        }
        // for (int i=0;i<wordIdx.size();i++)
        // {
        //     cout<<wordIdx[i].first<<" "<<wordIdx[i].second<<endl;
        // }
    
        if (wordIdx.size()==1)
        {
            string t="";
            for (int i=0;i<countSpaces;i++)
            {
                t=t+' ';
            }
            return text.substr(wordIdx[0].first,wordIdx[0].second+1)+t;
        }
        int space=countSpaces/(wordIdx.size()-1);
        // cout<<"countSpaces="<<countSpaces<<" "<<"space="<<space<<endl;
        // cout<<"#"<<text<<"#"<<endl;
        int start=0;
        for (int i=0;i<wordIdx.size();i++)
        {
            for (int x=wordIdx[i].first;x<=wordIdx[i].second;x++)
            {
                text[start]=text[x];
                start++;
            }
            for (int k=0;start<N && k<space;k++)
            {
                text[start]=' ';
                start++;
            }
            //cout<<text<<endl;
        }
        while(start<N)
        {
            text[start]=' ';
            start++;
        }
        //cout<<text<<endl;
        return text;
    }
};