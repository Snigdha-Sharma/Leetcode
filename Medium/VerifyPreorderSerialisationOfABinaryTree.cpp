class Solution 
{
    public:
    
    bool isNumber(string s) 
    { 
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]) == false) 
            {
                return false; 
            }
        }
        return true; 
    } 
    
    bool isValidSerialization(string preorder) 
    {
        stack<string> s;
        vector<string> tokens;
        stringstream check1(preorder);
        string intermediate;
        while(getline(check1,intermediate,','))
        {
            tokens.push_back(intermediate);
        }
        
        for (int i=0;i<tokens.size();i++)
        {
            
            if (tokens[i]=="#" && s.empty()==false && s.top()=="#")
            {
                s.pop();
                if (s.empty()==false && isNumber(s.top())==true)
                {
                    s.pop();
                    i--;   
                }
                else
                {
                    return false;
                }
            }
            else
            {
                s.push(tokens[i]);
            }
        }
        
        if (s.size()==1 && s.top()=="#")
        {
            return true;
        }
        return false;
    }
};