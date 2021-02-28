class Solution 
{
    public:
    string simplifyPath(string path) 
    {
        vector <string> tokens;  
        stringstream check1(path); 
        string intermediate; 
        while(getline(check1, intermediate, '/')) 
        { 
            tokens.push_back(intermediate); 
        }   
        stack<string> st;
        for (int i=0;i<tokens.size();i++)
        {
            //cout<<"l="<<tokens[i]<<endl;
            if (tokens[i].empty()==true || tokens[i]==".")
            {
                
            }
            else if (tokens[i]=="..")
            {
                if (st.empty()==false)
                {
                    st.pop();   
                }
            }
            else
            {
                st.push(tokens[i]);
            }
        }
        if (st.empty()==true)
        {
            return "/";
        }
        string ans="";
        while(!st.empty())
        {
            //cout<<"St="<<st.top()<<endl;
            ans=st.top()+ans;
            ans="/"+ans;
            st.pop();
        }
        return ans;
    }
};