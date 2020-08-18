//Application of bfs at multiple places simultaneously by using queue 

class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int> > q;
        int freq1=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (grid[i][j]==2)
                {
                    q.push(make_pair(i,j));
                }   
                if (grid[i][j]==1)
                {
                    freq1++;
                }
            }
        }
        int count=0;
        while(!q.empty() && freq1!=0)
        {
            int sz=q.size();
            for (int i=0;i<sz;i++)
            {
                //cout<<"Hey"<<endl;
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if (x>0 && grid[x-1][y]==1)//Up
                {
                    grid[x-1][y]=2;
                    q.push(make_pair(x-1,y));
                    freq1--;
                }
                //cout<<"Up done"<<endl;
                if (x<n-1 && grid[x+1][y]==1)//Down
                {
                    grid[x+1][y]=2;
                    q.push(make_pair(x+1,y));
                    freq1--;
                }
                //cout<<"Down done"<<endl;
                if (y>0 && grid[x][y-1]==1)//Left
                {
                    grid[x][y-1]=2;
                    q.push(make_pair(x,y-1));
                    freq1--;
                }
                //cout<<"Left done"<<endl;
                if (y<m-1 && grid[x][y+1]==1)//Right
                {
                    grid[x][y+1]=2;
                    q.push(make_pair(x,y+1));
                    freq1--;
                }
                //cout<<"Right done"<<endl;
            } 
            count++;
            // for (int i=0;i<n;i++)
            // {
            //     for (int j=0;j<m;j++)
            //     {
            //         cout<<grid[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
        }
        if (freq1==0)
        {
            return count;
        }
        else
        {
            return -1;
        }
    }
};