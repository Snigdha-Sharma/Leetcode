class Solution 
{
    public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int> > ans;
        if (root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int levelSize=0;
        while(!q.empty())
        {
            vector<int> currLevel;
            levelSize=q.size();
            for (int i=0;i<levelSize;i++)
            {
                TreeNode* k=q.front();
                currLevel.push_back(k->val);
                q.pop();
                if (k->left)
                {
                    q.push(k->left);   
                }
                if (k->right)
                {
                    q.push(k->right);   
                }
            }
            ans.push_back(currLevel);
            currLevel.clear();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};