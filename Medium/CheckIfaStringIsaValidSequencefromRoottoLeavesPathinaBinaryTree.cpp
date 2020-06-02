class Solution 
{
    public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) 
    {
        if (root==NULL)
        {
            return false;
        }
        stack<pair<TreeNode*,int> > s;
        bool ans=false;
        if (root->val==arr[0])
        {
            s.push(make_pair(root,0));
            int y=0;
            while(!s.empty() && y<arr.size())
            {
                TreeNode *x=s.top().first;
                int y=s.top().second;
                s.pop();
                int t=y+1,flag1=0,flag2=0;
                if (x->left!=NULL && t<arr.size() && x->left->val==arr[t])
                {
                    s.push(make_pair(x->left,t));
                    flag1=1;
                }
                if (x->right!=NULL && t<arr.size() && x->right->val==arr[t])
                {
                    s.push(make_pair(x->right,t));
                    flag2=1;
                }
                if (flag1==0 && flag2==0)
                {
                    if (x->left==NULL && x->right==NULL && y==arr.size()-1)
                    {
                        ans=true;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};