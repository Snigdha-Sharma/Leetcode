/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> s;
        TreeNode *temp=root;
        vector<int> ans;
        while(!s.empty() || temp!=NULL)
        {
            while(temp!=NULL)
            {
                s.push(temp);
                temp=temp->left;
            }
            temp=s.top();
            ans.push_back(temp->val);
            s.pop();
            temp=temp->right;
        }
        return ans;
    }
};