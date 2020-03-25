class Solution 
{
    public:
    bool hasCycle(ListNode *head) 
    {
        ListNode *slow=head,*fast=head;
        int flag=0;
        while(slow && fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast)
            {
                flag=1;
                break;
            }
        }
        if (flag)
        {
            return true;
        }
        return false;
    }
};