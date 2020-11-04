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
    
    void showMap(unordered_map<int,ListNode*> &umap)
    {
        for (auto it=umap.begin();it!=umap.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
    }
    
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        stack<ListNode*> st;
        unordered_map<int,ListNode*> umap;
        int cursum=0;
        ListNode *p=head;
        while(p)
        {
            if (p->val==0)
            {
                p=p->next;
                continue;
            }
            //cout<<p->val<<" ";
            //st.push(p);
            cursum=cursum+(p->val);
            //cout<<"cursum="<<cursum<<" ";
            if (cursum==0)
            {
                cout<<"1"<<endl;
                while(!st.empty())
                {
                    st.pop();
                    umap.clear();
                }
            }
            else if (umap.find(cursum)!=umap.end())
            {
                //cout<<"2"<<endl;
                int m=cursum;
                cursum=cursum-(p->val);
                //cout<<"m="<<m<<endl;
                while(cursum!=m)
                {
                    //cout<<"Map: "<<endl;
                    //showMap(umap);
                    umap.erase(cursum);
                    cursum=cursum-(st.top()->val);
                    
                    st.pop();
                    //cout<<"fsds="<<cursum<<endl;
                }
            }
            else
            {
                //cout<<"3"<<endl;
                umap[cursum]=p;
                st.push(p);
            }
            p=p->next;
        }
        ListNode *newHead=NULL;
        while(!st.empty())
        {
            st.top()->next=newHead;
            newHead=st.top();
            st.pop();
        }
        return newHead;
    }
};