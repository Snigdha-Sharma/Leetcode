class Trie 
{
    public:
    
    struct TrieNode
    {
        char val;
        int we;
        int count;
        TrieNode *child[26];
    };
    
    TrieNode *root;
    
    TrieNode* getNode(int index)
    {
        TrieNode *newNode=new TrieNode();
        newNode->val='a'+index;
        newNode->count=newNode->we=0;
        for (int i=0;i<26;++i)
        {
            newNode->child[i]=NULL;
        }
        return newNode;
    }
    
    /** Initialize your data structure here. */
    Trie() 
    {
        root=getNode('/'-'a');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        TrieNode *cur=root;
        int index;
        for (int i=0;i<word.size();i++)
        {
            index=word[i]-'a';
            if (cur->child[index]==NULL)
            {
                cur->child[index]=getNode(index);
            }
            cur->child[index]->count++;
            cur=cur->child[index];
        }
        cur->we++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        TrieNode *cur=root;
        int index;
        for (int i=0;i<word.size();i++)
        {
            index=word[i]-'a';
            if (cur->child[index]==NULL)
            {
                return false;
            }
            cur=cur->child[index];
        }
        return (cur->we>0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        TrieNode *cur=root;
        int index;
        for(int i=0;prefix[i]!='\0';++i)
        {
            index=prefix[i]-'a';
            if(cur->child[index]==NULL)
                return false;
            cur=cur->child[index];
        }
        return (cur->count> 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */