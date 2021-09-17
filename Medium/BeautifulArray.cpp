class Solution 
{
    public:
    vector<int> beautifulArray(int N) 
    {
        //For generating the next beautiful array from an array of size one less: generate odd elements as 2*el-1 and even as 2*el then concatenate both.
        vector<int> result={1};
        while(result.size()<N)
        {
            vector<int> temp;
            for(int i : result)
                if(i*2-1 <= N)
                    temp.push_back(i*2-1);
            for(int i:result)
                if(i*2 <= N)
                    temp.push_back(i*2);    
            result = temp;
        }
        return result;    
    }
};