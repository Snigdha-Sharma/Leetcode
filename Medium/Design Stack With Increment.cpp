class CustomStack 
{
    public:
    int sz;
    vector<int> s;
    int top=-1;
    CustomStack(int maxSize) 
    {
        sz=maxSize;
    }
    
    void push(int x) 
    {
        if (top<sz-1)
        {
            s.push_back(x);
            top++;
        }
    }
    
    int pop() 
    {
        if (top==-1)
        {
            return -1;
        }
        else
        {
            int el=s[top];
            s.pop_back();
            top--;
            return el;   
        }
    }
    
    void showStack()
    {
        for (int i=0;i<s.size();i++)
        {
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }
    
    void increment(int k, int val) 
    {
        for (int i=0;i<k && i<=top;i++)
        {
            s[i]=s[i]+val;
        }
    }
};


/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */