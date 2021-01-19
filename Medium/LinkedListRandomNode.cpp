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
    int len=0;
    ListNode *start;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) 
    {
        start=head;
        while(head!=NULL)
        {
            head=head->next;
            len++;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() 
    {
        int idx=rand()%len;
        ListNode *temp=start;
        for (int i=0;i<idx;i++)
        {
            temp=temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */