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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<int> s1,s2,ans;
        ListNode *sl1=l1,*sl2=l2;
        while(sl1)
        {
            s1.push(sl1->val);
            sl1=sl1->next;
        }
        while(sl2)
        {
            s2.push(sl2->val);
            sl2=sl2->next;
        }
        int carry=0;
        while(s1.empty()==false && s2.empty()==false)
        {
            int val=s1.top()+s2.top()+carry;
            if (val>9)
            {
                carry=1;
            }
            else
            {
                carry=0;
            }
            ans.push(val%10);
            s1.pop();
            s2.pop();
        }
        while(!s1.empty())
        {
            int val=s1.top()+carry;
            if (val>9)
            {
                carry=1;
            }
            else
            {
                carry=0;
            }
            ans.push(val%10);
            s1.pop();
        }
        while(!s2.empty())
        {
            int val=s2.top()+carry;
            if (val>9)
            {
                carry=1;
            }
            else
            {
                carry=0;
            }
            ans.push(val%10);
            s2.pop();
        }
        if (carry)
        {
            ans.push(carry);
        }
        ListNode *head=new ListNode(ans.top());
        ListNode *p=head;
        ans.pop();
        while(!ans.empty())
        {
            ListNode *temp=new ListNode(ans.top());
            p->next=temp;
            p=p->next;
            ans.pop();
        }
        return head;
    }
};