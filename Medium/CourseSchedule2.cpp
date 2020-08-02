//Topological sort using dfs and stack

class Solution 
{
    public:
    
    vector<int> visited;
    stack<int> temp;
    
    bool isCyclic(int vertex,vector<vector<int> > &adj)
    {
        if (visited[vertex]==2)//If a vertes that you visit is currently in the processing mode that means it is part of cycle
        {
            return true;
        }
        visited[vertex]=2;//Indicates that we are processing the current vertex
        for (int i=0;i<adj[vertex].size();++i)//visit all nodes connected to that vertex using dfs
        {
            if (visited[adj[vertex][i]]!=1)//Keep away all already processed nodes
            {
                if (isCyclic(adj[vertex][i],adj))
                {
                    return true;
                }
            }
        }
        visited[vertex]=1;//Indicating that node has been processed
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        //Deadlock detection in a graph
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        //Making adjacency list of given directed graph
        vector<vector<int> > adj(numCourses);
        for (int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        //Initialise visited global array
        for (int i=0;i<numCourses;i++)
        {
            visited.push_back(0);
        }
        
        //Check for cycle in given graph
        for (int i=0;i<numCourses;i++)
        {
            //If node is still unvisited
            if (visited[i]==0)
            {
                //returns true if that vertex is involved in a cycle
                if (isCyclic(i,adj)==true)
                {
                    //Break as soon as you get a cycle
                    return false;
                }   
            }
        }
        return true;
    }
    
    void dfs(int vertex,vector<vector<int> > &adjList)
    {
        visited[vertex]=1;
        for (int j=0;j<adjList[vertex].size();++j)
        {
            if (!visited[adjList[vertex][j]])
            {
                dfs(adjList[vertex][j],adjList);
            }
        }
        temp.push(vertex);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> ans;
        vector<vector<int> > adjList(numCourses,vector<int>(0));
        
        //Check if graph is DAG
        bool check=canFinish(numCourses,prerequisites);
        
        if (check==false)
        {
            return ans;
        }
        
        for (int i=0;i<numCourses;i++)
        {
            visited[i]=0;
        }
        
        for (int i=0;i<numCourses;i++)
        {
            visited.push_back(false);
        }
        
        for (int i=0;i<prerequisites.size();i++)
        {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        // for (int i=0;i<adjList.size();i++)
        // {
        //     cout<<i<<":";
        //     for (int j=0;j<adjList[i].size();j++)
        //     {
        //         cout<<adjList[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        for (int i=0;i<numCourses;i++)
        {
            if (visited[i]==0)
            {
                dfs(i,adjList);
            }
        }
        
        while(!temp.empty())
        {
            ans.push_back(temp.top());
            temp.pop();
        }
        
        return ans;
    }
};