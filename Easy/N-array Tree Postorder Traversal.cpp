class Solution 
{
    public:
    
    vector<int> ans;
    
    vector<int> postorder(Node* root) 
    {
        if (root==NULL)
        {
            return ans;
        }
        for (int i=0;i<root->children.size();i++)
        {
            postorder(root->children[i]);
        }
        ans.push_back(root->val);
        return ans;
    }
};

class Solution 
{
    public:
    
    vector<int> postorder(Node* root) 
    {
        vector<int> ans;
        if (root==NULL)
        {
            return ans;
        }
        stack<Node*> s;
        stack<Node*> s1;
        s.push(root);
        while(!s.empty())
        {
            Node* temp=s.top();
            s.pop();
            s1.push(temp);
            for (int i=0;i<temp->children.size();i++)
            {
                s.push(temp->children[i]);
            }
        }
        while(!s1.empty())
        {
            ans.push_back(s1.top()->val);
            s1.pop();
        }
        return ans;
    }
};