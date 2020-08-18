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
    
    void showList(ListNode *head)
    {
        while(head)
        {
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
    }
    
    ListNode* merge(ListNode *l1,ListNode *l2)
    {
        // cout<<"l1= ";
        // showList(l1);
        // cout<<"l2= ";
        // showList(l2);
        ListNode *head=NULL,*p;
        while(l1 && l2)
        {
            if (l1->val<l2->val)
            {
                if (head==NULL)
                {
                    head=l1;
                    p=head;
                }                                       
                else                                    
                {
                    p->next=l1;
                    p=p->next;
                }
                l1=l1->next;
                p->next=NULL;
            }
            else
            {
                if (head==NULL)
                {
                    head=l2;
                    p=head;
                }
                else
                {
                    p->next=l2;
                    p=p->next;
                }
                l2=l2->next;
                p->next=NULL;
            }
            //cout<<p->val<<" ";
        }  
        //cout<<endl;
        if(l1)
        {
            p->next=l1;
        }
        if(l2)
        {
            p->next=l2;
        }
        // cout<<"Merged:";
        // showList(head);
        return head;
    }
    
    ListNode* mergeSort(ListNode *head)
    {
        //If a list can't be split
        if (head==NULL || head->next==NULL)
        {
            return head;
        }
        
        //Else split the list into 2 parts
        ListNode *slow=head,*fast=head,*prev=head;
        
        while(fast && fast->next)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next;
            if (fast->next)
            {
                fast=fast->next;
            }
        }
        prev->next=NULL;
        ListNode *l1=head,*l2=slow;
        // showList(l1);
        // showList(l2);
        
        l1=mergeSort(l1);
        l2=mergeSort(l2);
        return merge(l1,l2);
    }
    
    ListNode* sortList(ListNode* head) 
    {
        if (head==NULL || head->next==NULL)
        {
            return head;
        }
        return mergeSort(head);
    }
};