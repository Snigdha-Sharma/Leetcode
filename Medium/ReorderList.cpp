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
    
    ListNode *rhead;
    
    ListNode* reverseList(ListNode *head)
    {
        if(head== NULL)
        {
            return NULL;
        }
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *next=NULL;
        while(curr!=NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) 
    {
        if (head==NULL || head->next==NULL)
        {
            return;
        }
        ListNode *slow=head,*fast=head;
        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=head;
        ListNode *secondHalfHead=reverseList(slow),*firstHalfHead=head;
        ListNode *temp1=NULL,*temp2=NULL;
        while(firstHalfHead && secondHalfHead)
        {
            temp1=firstHalfHead->next;
            temp2=secondHalfHead->next;
            firstHalfHead->next=secondHalfHead;
            firstHalfHead=temp1;
            secondHalfHead->next=firstHalfHead;
            secondHalfHead=temp2;
        }
        if (firstHalfHead!=NULL)
        {
            firstHalfHead->next=NULL;
        }
    }
};