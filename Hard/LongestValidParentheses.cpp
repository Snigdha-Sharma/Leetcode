class Solution 
{
    public:
    //Instead of finding every possible string and checking its validity, we can make use of stack while scanning the given string to check if the string scanned so far
    // is valid, and also the length of the longest valid string. In order to do so, we start by pushing -1−1 onto the stack.
    //For every \text{‘(’}‘(’ encountered, we push its index onto the stack.
    //For every \text{‘)’}‘)’ encountered, we pop the topmost element and subtract the current element's index from the top element of the stack, which gives the length
    // of the currently encountered valid string of parentheses. If while popping the element, the stack becomes empty, we push the current element's index onto the 
    //stack. In this way, we keep on calculating the lengths of the valid substrings, and return the length of the longest valid string at the end.
    int longestValidParentheses(string s) 
    {
        stack<int> st;
        st.push(-1);
        int ans=0;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='(') 
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty()==true)
                    st.push(i);
                else
                {
                    ans=max(ans,i-st.top());
                }
            }
        }
        return ans;
    }
};

//Solution 2: O(1) space, O(N) time
class Solution 
{
    public:
    int longestValidParentheses(string s) 
    {
        int left=0,right=0,ans=0;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='(')
            {
                right++;
            }
            else
            {
                left++;
            }
            if (right<left)
            {
                left=0;
                right=0;
            }
            else if (left==right)
            {
                ans=max(ans,left+right);
            }
            
        }
        //cout<<ans;
        left=0,right=0;
        for (int i=s.size()-1;i>=0;i--)
        {
            if (s[i]=='(')
            {
                right++;
            }
            else
            {
                left++;
            }
            if (right>left)
            {
                left=0;
                right=0;
            }
            else if (left==right)
            {
                ans=max(ans,left+right);
            }
        }
        return ans;
    }
};