/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution 
{
    public:
    Node* cloneGraph(Node* node) 
    {
        if (node==NULL)//If graph does not exist
        {
            return NULL;
        }
        if (node->neighbors.size()==0)//If graph has only one node with no neighbours
        {
            Node* nnode=new Node(node->val);
            return nnode;
        }
        unordered_map<int,Node*> umap;//Stores nodes which have already been created
        unordered_set<int> uset,uvisited;//Stores nodes whhich are completed-all its connections are complete
        queue<Node*> q;
        q.push(node);
        uvisited.insert(node->val);
        while(!q.empty())
        {
            Node* popped=q.front();
            Node* nnode;
            if (umap.find(popped->val)==umap.end())
            {
                nnode=new Node(popped->val);
                umap[popped->val]=nnode;
            }
            else
            {
                nnode=umap[popped->val];
            }
            for (int i=0;i<popped->neighbors.size();i++)
            {
                Node* nei=popped->neighbors[i];
                if (uset.find(nei->val)==uset.end() && uvisited.find(nei->val)==uvisited.end())
                {
                    q.push(nei);
                    uvisited.insert(nei->val);
                }
                Node *cnode;
                if (umap.find(nei->val)==umap.end())
                {
                    cnode=new Node(nei->val);
                    umap[nei->val]=cnode;
                }
                else
                {
                    cnode=umap[nei->val];
                }
                nnode->neighbors.push_back(cnode);
            }
            uset.insert(popped->val);
            q.pop();
        }
        return umap[1];
    }
};






