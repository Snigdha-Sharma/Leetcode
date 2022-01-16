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
class Solution 
{
    public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if (head==NULL || head->next==NULL || head->next->next==NULL)//If length of linked list is less than equal to 2 return as it is
        {
            return head;
        }
        ListNode *oddHead=head,*evenHead=head->next,*p=oddHead,*q=evenHead,*prev=p;
        while(p && q)
        {
            prev=p;
            p->next=q->next;
            if (p->next)
                q->next=p->next->next;
            p=p->next;
            q=q->next;
        }
        if (p)
        {
            p->next=evenHead;
        }
        else
        {
            prev->next=evenHead;
        }
        return oddHead;
    }
};