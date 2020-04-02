class Solution 
{
    public:
    
    vector<int> ans;
    
    vector<int> preorder(Node* root) 
    {
        if (root==NULL)
        {
            return ans;
        }
        ans.push_back(root->val);
        for (int i=0;i<root->children.size();i++)
        {
            preorder(root->children[i]);
        }
        return ans;
    }
};

class Solution 
{
    public:
    
    vector<int> preorder(Node* root) 
    {
        vector<int> ans;
        if (root==NULL)
        {
            return ans;
        }
        stack<Node*> s;
        s.push(root);
        while(!s.empty())
        {
            Node* temp=s.top();
            ans.push_back(s.top()->val);
            s.pop();
            for (int i=temp->children.size()-1;i>=0;i--)
            {
                s.push(temp->children[i]);
            }
        }
        return ans;
    }
};