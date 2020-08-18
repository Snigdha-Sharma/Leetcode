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
    
    int ans=0;
    unordered_map<int,int> umap;
    
    void showmap(unordered_map<int,int> umap)
    {
        for (auto it=umap.begin();it!=umap.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
        cout<<endl;
    }
    
    
    void helper(TreeNode *root,int cursum,int sum)
    {   
        if (root==NULL)
        {
            return;
        }
        cursum+=root->val;//Add each nodes value to cursum as soon as you reach
        if(umap.find(cursum-sum)!=umap.end())//Find if cursum-sum exists in array. If it does add ho many times it has occured
        {
            ans=ans+umap[cursum-sum];
        }
        umap[cursum]++;//Increment cursum now after checking
        helper(root->left,cursum,sum);//Call for left
        helper(root->right,cursum,sum);//Call for right
        umap[cursum]--;//After you are dne with the node remove cumulative sum till it from map
    }
    
    int pathSum(TreeNode* root, int sum) 
    {
        umap[0]=1;//When we initialise umap[0] with 1 we do not check is currsum==sum because then that condition is checked in umap.find(cursum-sum) case only
        helper(root,0,sum);
        return ans;
    }
};