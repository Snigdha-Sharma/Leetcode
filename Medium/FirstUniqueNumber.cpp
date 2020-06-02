class FirstUnique 
{
    public:
    
    map<int,int> m;
    vector<int> input;
    
    FirstUnique(vector<int>& nums) 
    {
        for (int i=0;i<nums.size();i++)
        {
            add(nums[i]);
        }
    }
    
    int showFirstUnique() 
    {
        for (int i=0;i<input.size();i++)
        {
            if (m[input[i]]==1)
            {
                return input[i];
            }
        }
        return -1;
    }
    
    void add(int value) 
    {
        if (m.find(value)!=m.end())
        {
            m[value]++;
        }
        else
        {
            m[value]=1;
            input.push_back(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */