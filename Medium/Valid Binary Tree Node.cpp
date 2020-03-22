class Solution 
{
    public:
    bool ans;
    
    void optimization(vector<int>& child, vector<int>& parent) 
    {
    	for(int i = 0; i < child.size() && ans == true; i++) 
        { 
        	if(child[i] != -1) 
            { 
            	if(parent[child[i]] == -1) 
                {
            		parent[child[i]] = i;
                }
                else 
                { 
                	ans = false;
                }
            }
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        vector<int>parent(n, -1);
        int root=0;
        ans = true; 
        optimization(leftChild, parent);		
        optimization(rightChild, parent);
        return ans && count(parent.begin(), parent.end(), -1) == 1;
    }
};