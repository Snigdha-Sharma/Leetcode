/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator 
{
    public:
    
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        makeFlatList(nestedList);
    }
    
    int next() 
    {
        return flatList[idx++];
    }
    
    bool hasNext() 
    {
        if(idx==flatList.size())
        {
            return false;
        }
        return true;
    }
    
    void makeFlatList(vector<NestedInteger> &nval)
    {
        for(int i=0;i<nval.size();i++)
        {
            if(nval[i].isInteger())
            {
                flatList.push_back(nval[i].getInteger());
            }   
            else
            {
                makeFlatList(nval[i].getList());
            }
        }
    }
    
    private:
    vector<int> flatList;
    int idx=0;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */