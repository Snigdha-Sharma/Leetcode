class MinStack 
{
    public:
    /** initialize your data structure here. */
    
    stack<long long int> s;
    long long int minEl=0;
    
    MinStack() 
    {
        while(!s.empty())
        {
            s.pop();
        }
        minEl=0;
    }
    
    void push(int x) 
    {
        //x=(long long int)x;
        //cout<<"x="<<x<<endl;
        if (s.empty())
        {
            s.push(x);
            minEl=x;
        }
        else
        {
            if (x<minEl)
            {
                long long int y=x;
                s.push(2*y-minEl);
                minEl=x;
            }
            else
            {
                s.push(x);
            }   
        }
    }
    
    void pop() 
    {
        long long int t = s.top(); 
        s.pop(); 
        if (t < minEl) 
        { 
            minEl = 2*minEl- t; 
        } 
    }
    
    int top() 
    {
        long long int t=s.top();
        if (t<minEl)
        {
            return minEl;
        }
        else
        {
            return t;
        }
    }
    
    int getMin() 
    {
        return minEl;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */