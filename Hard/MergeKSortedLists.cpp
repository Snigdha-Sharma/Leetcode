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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i=0;i<lists.size();i++)
        {
            while(lists[i]!=NULL)
            {
                pq.push(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        if(pq.empty()==true)
        {
            return NULL;
        }
        ListNode *head=new ListNode(pq.top()),*ans=head;
        pq.pop();
        while(!pq.empty())
        {
            head->next=new ListNode(pq.top());
            head=head->next;
            pq.pop();
        }
        return ans;
    }
};