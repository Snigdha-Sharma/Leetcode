/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution 
{
    public:
    
    Node* copyRandomList(Node* head) 
    {
        if (head==NULL)
        {
            return NULL;
        }
        if (head->next==NULL)
        {
            Node *nnode=new Node(head->val);
            nnode->next=NULL;
            if (head->random==NULL)
            {
                nnode->random=NULL;
            }
            if (head->random==head)
            {
                nnode->random=nnode;
            }
            return nnode;
        }
        unordered_map<Node*,Node*> umap;
        Node *trav=head;
        while(trav)
        {
            Node *nnode=new Node(trav->val);
            umap[trav]=nnode;
            trav=trav->next;
        }
        trav=head;
        while(trav)
        {
            umap[trav]->next=umap[trav->next];
            umap[trav]->random=umap[trav->random];
            trav=trav->next;
        }
        return umap[head];
    }
};