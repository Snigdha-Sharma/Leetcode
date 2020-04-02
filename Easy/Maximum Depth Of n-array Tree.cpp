class Solution 
{
    public:
    int maxDepth(Node* root) 
    {
        if (root==NULL)
        {
            return 0;
        }
        if (root->children.size()==0)
        {
            return 1;
        }
        int m=INT_MIN;
        for (int i=0;i<root->children.size();i++)
        {
            m=max(m,maxDepth(root->children[i]));
        }
        return m+1;
    }
};