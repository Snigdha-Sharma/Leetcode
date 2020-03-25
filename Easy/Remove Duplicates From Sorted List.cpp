class Solution 
{
    public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode *p=head->next,*q=head;
        while(p)
        {
            if (p->val==q->val)
            {
                q->next=p->next;
            }
            else
            {
                q=q->next;   
            }
            p=p->next;
        }
        return head;
    }
};