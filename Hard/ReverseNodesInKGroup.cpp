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
    
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev=NULL,*curr=head,*future=head->next;
        while(future)
        {
            curr->next=prev;
            prev=curr;
            curr=future;
            future=future->next;
        }
        curr->next=prev;
        ListNode* temp=curr;
        // while(curr)
        // {
        //     cout<<curr->val<<" ";
        //     curr=curr->next;
        // }
        // cout<<endl;
        return curr;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *ans=NULL,*q=ans; 
        ListNode *p=head;
        while(p)
        {
            ListNode *start=p;
            for (int i=0;i<k-1;i++)
            {
                if (p==NULL)
                {
                    q->next=start;
                    return ans;
                }
                p=p->next;
            }
            if (p==NULL)
            {
                q->next=start;
                return ans;
            }
            ListNode *end=p;
            p=p->next;
            end->next=NULL;
            if (ans==NULL)
            {
                ans=reverseList(start);
            }
            else
            {
                q->next=reverseList(start);
            }
            q=start;
        }
        return ans;
    }
};