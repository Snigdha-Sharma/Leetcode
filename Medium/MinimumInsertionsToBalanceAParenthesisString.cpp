class Solution 
{
    public:
    int minInsertions(string s) 
    {
        stack<char> st;
        int ans=0;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='(')
            {
                //cout<<"1";
                st.push(s[i]);
            }
            else 
            {
                //Single Closing Bracket till now
                if (i+1<s.size())
                {
                    if (s[i+1]==')')
                    {
                        //Double Closing Bracket
                        if (st.empty()==true)
                        {
                            //cout<<"2";
                            ans=ans+1;
                        }
                        else
                        {
                            //cout<<"3";
                            st.pop();
                        }
                        i++;
                    }
                    else
                    {
                        //cout<<"4";
                        if(st.empty()==true)
                        {
                            ans=ans+2;
                        }
                        else
                        {
                            ans=ans+1;
                            st.pop();
                        } 
                    }
                }
                else
                {
                    
                    if (st.empty()==true)
                    {
                        //cout<<"5";
                        ans=ans+2;
                    }
                    else
                    {
                        //cout<<"6";
                        ans=ans+1;
                        st.pop();
                    } 
                }
            }
        }
        ans=ans+2*st.size();
        return ans;
    }
};