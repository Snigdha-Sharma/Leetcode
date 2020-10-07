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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL)
        {
            return NULL;
        }
        int len=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        
        k=k%len;
        
        ListNode *kback;
        temp=head;
        for (int i=0;i<k;i++)
        {
            temp=temp->next;   
        }
        kback=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            kback=kback->next;
        }
        temp->next=head;
        head=kback->next;
        kback->next=NULL;
        return head;
    }
};