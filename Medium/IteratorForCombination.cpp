class CombinationIterator 
{
    public:
    
    priority_queue<string,vector<string>,greater<string> > pq;
    
    CombinationIterator(string characters, int combinationLength) 
    {
        long long int sz=pow(2,characters.size());
        for (long long int i=0;i<sz;i++)
        {
            string m="";
            for (long int j=0;j<characters.size();j++)
            {
                if (i&(1<<j))
                {
                    m=m+characters[j];
                }
            }
            //cout<<m<<" ";
            if (m.size()==combinationLength)
            {
                pq.push(m);
            }
        }
    }
    
    string next() 
    {
        string ans=pq.top();
        pq.pop();
        return ans;
    }
    
    bool hasNext() 
    {
        if (pq.size()>0)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */