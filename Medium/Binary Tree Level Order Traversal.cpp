class Solution 
{
    public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int> > ans;
        if (root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int levelSz;
        vector<int> level;
        while(!q.empty())
        {
            levelSz=q.size();
            for (int i=0;i<levelSz;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            ans.push_back(level);
            level.clear();
        }
        return ans;
    }
};