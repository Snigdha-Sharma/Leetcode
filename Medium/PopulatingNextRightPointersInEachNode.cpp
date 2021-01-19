/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution 
{
    public:

    Node* connect(Node* root) 
    {
        if (root==NULL || (root->left==NULL && root->right==NULL))
        {
            return root;
        }
        Node *start=root;
        while (start)
        {
            Node *temp=start;
            if (temp->left->left)
            {
                start=temp->left;
            }
            else
            {
                start=NULL;
            }
            do
            {
                temp->left->next=temp->right;
                if (temp->next)
                {
                    temp->right->next=temp->next->left;
                }
                else
                {
                    temp->right->next=NULL;
                }
                temp=temp->next;
            }while(temp);
        }
        return root;
    }
};