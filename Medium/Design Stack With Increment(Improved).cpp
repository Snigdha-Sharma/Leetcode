class CustomStack 
{
    public:
    int sz;
    vector<int> s;
    vector<int> spc;
    int top=-1;
    
    CustomStack(int maxSize) 
    {
        s = vector<int>(maxSize, 0);        
        spc = vector<int>(maxSize, 0);
        sz = maxSize;
    }
    
    void push(int x) 
    {
       
        if (top<sz-1) 
        {
            top++;
            s[top] = x;
        }
    }
    
    void showSPC()
    {
        for (int i=0;i<spc.size();i++)
        {
            cout<<spc[i]<<" ";
        }
        cout<<endl;
    }
    //
    int pop() 
    {
        if (top==-1) 
        {
            return -1;
        }
        else
        {
            int el;
            el=spc[top]+s[top];
            s.pop_back();
            if (top-1>=0)
            {
                spc[top-1]=spc[top-1]+spc[top]; 
            }
            spc[top]=0; 
            top--;
            return el;   
        }
    }
    
    void increment(int k, int val) 
    {
        if (top!=-1) 
        {
            if (k<=top) 
            {
                spc[k-1]=spc[k-1]+val;   
            }
            else
            {
                spc[top]=spc[top]+val;
            }   
        }
    }
};