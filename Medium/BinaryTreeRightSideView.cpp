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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        stack<TreeNode*> st;
        if (root)
        {
            st.push(root);
        }
        while(!st.empty())
        {
            ans.push_back(st.top()->val);
            stack<TreeNode*> nst;
            while(!st.empty())
            {
                if (st.top()->right)
                {
                    nst.push(st.top()->right);
                }
                if (st.top()->left)
                {
                    nst.push(st.top()->left);
                }
                st.pop();
            }
            while(!nst.empty())
            {
                st.push(nst.top());
                nst.pop();
            }
        }
        return ans;
    }
};