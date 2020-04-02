class Solution 
{
    public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> ans;
        if (root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int levelSize=0;
        double avg=0;
        while(!q.empty())
        {
            avg=0;
            levelSize=q.size();
            for (int i=0;i<levelSize;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                avg=avg+curr->val;
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            avg=avg/(double)levelSize;
            ans.push_back(avg);
        }
        return ans;
    }
};