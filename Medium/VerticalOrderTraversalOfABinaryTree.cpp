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
    
    vector<vector<int> > store;
    
    void helper(TreeNode *root, int x, int y)
    {
        vector<int> temp;
        if(root==NULL)
        {
            return;
        }
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(root->val);
        store.push_back(temp);
        helper(root->left,x-1,y-1);
        helper(root->right,x+1,y-1);
    }
    
    static bool compare(vector<int> &v1, vector<int> &v2)
    {
        if (v1[0]<v2[0])
        {
            return true;
        }
        else if (v1[0]==v2[0])
        {
            if (v1[1]>v2[1])
            {
                return true;
            }
            else if (v1[1]==v2[1])
            {
                return v1[2]<v2[2];
            }
        }
        return false;
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int> > ans;
        helper(root,0,0);
        
        sort(store.begin(),store.end(),compare);
        
        // for (int i=0;i<store.size();i++)
        // {
        //     cout<<store[i][0]<<" "<<store[i][1]<<" "<<store[i][2]<<endl;
        // }
        
        int cur_x=0;
        
        for (int i=0;i<store.size();i++)
        {
            cur_x=store[i][0];
            vector<int> temp;
            while(i<store.size() && cur_x==store[i][0])
            {
                temp.push_back(store[i][2]);
                i++;
            }
            i--;
            ans.push_back(temp);
        }
        
        return ans;
    }
};