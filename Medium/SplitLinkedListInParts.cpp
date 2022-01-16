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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        //If there are N nodes in the list, and k parts, then every part has N/k elements, except the first N%k parts have an extra one.
        vector<ListNode*> ans;
        ListNode *p=head;
        int len=0;
        while(p)
        {
            len++;
            p=p->next;
        }
        p=head;
        int noOfLargerParts=len%k,sz=len/k;
        for (int i=0;i<k;i++)
        {
            ListNode *prev=p;
            ans.push_back(p);
            if (noOfLargerParts>0)
            {
                noOfLargerParts--;
                prev=p;
                p=p->next;
                
            }
            
            int temp=0;
            
            while(temp<sz)
            {
                prev=p;
                p=p->next; 
                temp++;
            }
            if (prev)
                prev->next=NULL;
        }
        return ans;
    }
};