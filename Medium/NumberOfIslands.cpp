//dfs or bfs..Major error was call by value and call by reference confusion

class Solution 
{
    public:
    
    int findLeft(pair<int,int> p,vector<vector<char>>& grid)
    {
        int ans=0;
        if (p.second-1>=0 && grid[p.first][p.second-1]=='1')
        {
            ans=1;
        }
        return ans;
    }
    
    int findRight(pair<int,int> p,vector<vector<char>>& grid)
    {
        int ans=0;
        if (p.second+1<grid[0].size() && grid[p.first][p.second+1]=='1')
        {
            ans=1;
        }
        return ans;
    }
    
    int findUp(pair<int,int> p,vector<vector<char>>& grid)
    {
        int ans=0;
        if (p.first-1>=0 && grid[p.first-1][p.second]=='1')
        {
            ans=1;
        }
        return ans;
    }
    
    int findDown(pair<int,int> p,vector<vector<char>>& grid)
    {
        int ans=0;
        if (p.first+1<grid.size() && grid[p.first+1][p.second]=='1')
        {
            ans=1;
        }
        return ans;
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        stack<pair<int,int> > s;
        int ans=0;
        for (int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid[0].size();j++)
            {
                if (grid[i][j]=='1')
                {
                    s.push(make_pair(i,j));
                    ans++;
                    while(!s.empty())
                    {
                        pair<int,int> test=s.top();
                        grid[test.first][test.second]=0;
                        s.pop();
                        if (findLeft(test,grid))
                        {
                            s.push(make_pair(test.first,test.second-1));
                        }
                        if (findRight(test,grid))
                        {
                            s.push(make_pair(test.first,test.second+1));
                        }
                        if (findUp(test,grid))
                        {
                            s.push(make_pair(test.first-1,test.second));
                        }
                        if (findDown(test,grid))
                        {
                            s.push(make_pair(test.first+1,test.second));
                        }
                    }
                }
            }
        }
        return ans;
    }
};