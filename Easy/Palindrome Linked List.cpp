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
    
    bool isPalindrome(ListNode* head) 
    {
        if (head==NULL || head->next==NULL)
        {
            return true;
        }
        ListNode *p=head->next,*q=head,*r=head;
        while(p && p->next)
        {
            q=q->next;
            p=p->next->next;
        }
        bool ans=true;
        q->next=reverseList(q->next);
        q=q->next;
        while(q)
        {
            if (r->val!=q->val)
            {
                ans=false;
                break;
            }
            q=q->next;
            r=r->next;
        }
        return ans;
    }
};