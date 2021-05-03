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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode *p=head;
        k--;
        vector<int> v;
        while(p)
        {
            v.push_back(p->val);
            p=p->next;
        }
        int t=v[k];
        v[k]=v[v.size()-k-1];
        v[v.size()-k-1]=t;
        ListNode *nhead=new ListNode(v[0]);
        p=nhead;
        for(int i=1;i<v.size();i++)
        {
            p->next=new ListNode(v[i]);
            p=p->next;
        }
        return nhead;
    }
};