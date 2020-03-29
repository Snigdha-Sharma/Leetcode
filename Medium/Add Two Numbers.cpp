class Solution 
{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *head,*head1=l1->next,*head2=l2->next,*p;
        head=new ListNode((l1->val+l2->val)%10);
        int carry=(l1->val+l2->val)/10;
        p=head;
        while(head1 && head2)
        {
            ListNode *temp=new ListNode((head1->val+head2->val+carry)%10);
            carry=(head1->val+head2->val+carry)/10;
            p->next=temp;
            p=p->next;
            head1=head1->next;
            head2=head2->next;
        }
        if (carry && head1==NULL && head2==NULL)
        {
            ListNode *temp=new ListNode(carry);
            p->next=temp;
            return head;
        }
        else if (carry && head1)
        {
            p->next=head1;
            ListNode *q=p;
            p=p->next;
            while(carry && p)
            {
                p->val=(p->val+carry);
                carry=(p->val)/10;
                p->val=p->val%10;
                q=p;
                p=p->next;
            }
            if (carry)
            {
                ListNode *temp=new ListNode(carry);
                q->next=temp;
            }
            return head;
        }
        else if(carry && head2)
        {
            p->next=head2;
            ListNode *q=p;
            p=p->next;
            while(carry && p)
            {
                p->val=(p->val+carry);
                carry=(p->val)/10;
                p->val=p->val%10;
                q=p;
                p=p->next;
            }
            if (carry)
            {
                ListNode *temp=new ListNode(carry);
                q->next=temp;
            }
            return head;
        }
        else if (carry==0 && head1)
        {
            p->next=head1;
            return head;
        }
        else
        {
            p->next=head2;
            return head;
        }
    }
};