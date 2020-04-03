class Solution 
{
    public:
    
    vector<int> ans;
    
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if (root==NULL)
        {
            return ans;
        }
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};

class Solution 
{
    public:
    
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        if (root==NULL)
        {
            return ans;
        }
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            ans.push_back(s.top()->val);
            TreeNode* temp=s.top();
            s.pop();
            if (temp->right)
            {
                s.push(temp->right);   
            }
            if (temp->left)
            {
                s.push(temp->left);   
            }
        }
        return ans;
    }
};