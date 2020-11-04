/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//The speciality of the node which is the entry point of the cycle is that it is being pointed by two nodes, one outside the cycle and 
//one inside the cycle, We have made use of this concept only.

class Solution 
{
    public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *slow=head,*fast=head;
        while(slow && fast && fast->next)
        {
            //cout<<"Slow:"<<slow->val<<",Fast:"<<fast->val;
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast)
            {
                unordered_set<ListNode*> s;
                while(s.find(slow)==s.end())
                {
                    s.insert(slow);
                    slow=slow->next;
                }    
                ListNode *p=head;
                while(p!=NULL)
                {
                    if (s.find(p)!=s.end())
                    {
                        return p;
                    }
                    p=p->next;
                }
            }
        }
        return NULL;
    }
};