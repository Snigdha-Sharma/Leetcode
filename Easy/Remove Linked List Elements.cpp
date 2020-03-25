class Solution 
{
    public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        if (head==NULL)
        {
            return head;
        }
        ListNode *p=head,*q=head;
        while(p)
        {
            if (p==head && p->val==val)
            {
                head=p->next;
                p=p->next;
            }
            else if (p->next==NULL && p->val==val)
            {
                q->next=NULL;
                p=NULL;
            }
            else if (p->val==val)
            {
                p->val=p->next->val;
                p->next=p->next->next;
            }
            else
            {
                q=p;
                p=p->next;
            }
        }
        return head;
    }
};