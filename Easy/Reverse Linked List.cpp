class Solution 
{
    public:
    ListNode* reverseList(ListNode* head) 
    {
        if (head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode *p=head->next,*q=head,*r=NULL;
        while(p)
        {
            q->next=r;
            r=q;
            q=p;
            p=p->next;
        }
        q->next=r;
        return q;
    }
};