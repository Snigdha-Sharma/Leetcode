class Solution 
{
    public:
   
    //Time Complexity O(N*M*K) Space Complexity )(N*M*k)
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        int N=grid.size(),M=grid[0].size(),ans=0;
        queue<vector<int> > q;
        vector<int> temp(3,-1);
        vector<vector<int> > lives(N,vector<int> (M,-1));// If k was always 0 then you would only need to keep track whether the cell visited or not.
        // But in this case you are free to revisit a cell. We revisit a cell only when we get a new way to reach there with more lives saved.
        lives[0][0]=k;
        temp[0]=0;
        temp[1]=0;
        temp[2]=k;
        q.push(temp);
        
        //If you have sufficient number of lives that you can break all barriers then answer is directly the Manhattan distance
        if (k >= N + M - 2) 
        {
            return N + M- 2;
        }
        
        vector<vector<int> > directions={{1,0},{0,1},{0,-1},{-1,0}};
        while(!q.empty())
        {
            int sz=q.size();
            for (int i=0;i<sz;i++)
            {
                vector<int> popped=q.front();
                q.pop();
                //cout<<popped[0]<<" "<<popped[1]<<" "<<popped[2]<<", val="<<grid[popped[0]][popped[1]]<<",life="<<lives[popped[0]][popped[1]]<<endl;
                if (popped[0]==N-1 && popped[1]==M-1)// If that cell is a destination
                {
                    return ans;
                }
                else
                {
                    for (int i=0;i<4;i++)//Visit cells in all directions
                    {
                        int nr=popped[0]+directions[i][0], nc=popped[1]+directions[i][1];
                        if (nr>=0 && nr<N && nc>=0 && nc<M) // If cell is a valid cell of the grid 
                        {
                            vector<int> temp(3,-1);
                            temp[0]=nr;
                            temp[1]=nc;
                            if (grid[nr][nc]==0)
                            {
                                temp[2]=popped[2];
                            }
                            else
                            {
                                temp[2]=popped[2]-1;
                            }
                            if (temp[2]>=0 && popped[2]>lives[nr][nc])// Only push a new cell in the queue if it is not a boundary and we are revisiting it with better number of lives
                            {
                                lives[nr][nc]=temp[2];
                                q.push(temp);
                            }    
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};