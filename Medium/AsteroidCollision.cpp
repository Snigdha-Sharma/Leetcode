class Solution 
{
    public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int> ans;
        stack<int> s;
        s.push(asteroids[0]);
        for (int i=1;i<asteroids.size();i++)
        {
            if (s.empty()==false && s.top()>0 && asteroids[i]<0 && abs(asteroids[i])>abs(s.top()))
            {
                while(s.empty()==false && s.top()>0 && abs(asteroids[i])>abs(s.top()))
                {
                    s.pop();
                }
                i--;
            }
            else if (s.empty()==false && s.top()>0 && asteroids[i]<0 && abs(asteroids[i])==abs(s.top()))
            {
                s.pop();
            }
            else if (s.empty()==false && s.top()>0 && asteroids[i]<0 && abs(asteroids[i])<abs(s.top()))
            {
                
            }
            else
            {
                s.push(asteroids[i]);
            }
        }
        for (int i=0;i<s.size();i++)
        {
            ans.push_back(0);
        }
        int h=s.size()-1;
        while(!s.empty())
        {
            ans[h]=s.top();
            h--;
            s.pop();
        }
        return ans;
    }
};