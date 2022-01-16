/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    //This BST will be height balanced. Simply find the middle of linked list and mark is at root. Left from the middle node will go in left subtree and right will go 
    //in right subtree. Use recursion to obtain rest of the tree.

    ListNode *findMiddleNode(ListNode *head)
    {
        //cout<<"Head: "<<head->val<<endl;
        ListNode *p=head,*prev=p;
        int c=0;
        while(head)
        {
            //cout<<head->val<<" ";
            if (c%2==1)
            {
                prev=p;
                p=p->next;
            }
            head=head->next;
            c++;
        }
        //cout<<"prev->val: "<<prev->val<<",prev->next: "<<prev->next<<endl;
        return prev;
    }
    
    TreeNode *helper(TreeNode *root,ListNode *head)
    {
        if (head==NULL)
        {
            return NULL;
        }
        ListNode *middle=findMiddleNode(head);
        if (middle->next==NULL)
        {
            return new TreeNode(middle->val);
        }
        root=new TreeNode(middle->next->val);
        ListNode *headRight=middle->next->next;
        middle->next=NULL;
        root->left=helper(root,head);
        root->right=helper(root,headRight);
        //cout<<"root->val: "<<root->val<<endl;
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) 
    {
        TreeNode *ans;
        ans=helper(ans,head);
        return ans;
    }
};