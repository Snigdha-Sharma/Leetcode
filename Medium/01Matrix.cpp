//Using DP
class Solution 
{
    public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size();
        if (rows == 0) 
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX - 100000));

        //First pass: check for left and top
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                if (matrix[i][j] == 0) 
                {
                    dist[i][j] = 0;
                } 
                else 
                {
                    if (i > 0)
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        //Second pass: check for bottom and right
        for (int i = rows - 1; i >= 0; i--) 
        {
            for (int j = cols - 1; j >= 0; j--) 
            {
                if (i < rows - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < cols - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
        return dist;
    }
};

//Using multi source BFS
class Solution 
{
    public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int N=mat.size(),M=mat[0].size();
        vector<vector<int> > ans(N,vector<int> (M,INT_MAX));
        queue<pair<int,int> > q;
        
        //Taking 0 as the source for our bfs start since we already know that the answer here is 0 
        for (int i=0;i<N;i++)
        {
            for (int j=0;j<M;j++)
            {
                if (mat[i][j]==0)
                {
                    ans[i][j]=0;
                    mat[i][j]=-1;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int> > directions={{-1,0},{1,0},{0,1},{0,-1}};
        int depth=1;
        
        //After each iteration of the while loop we are going one step deeper 
        while(!q.empty())
        {
            int sz=q.size();
            for (int i=0;i<sz;i++)
            {
                pair<int,int> popped=q.front();
                q.pop();
                int x=popped.first,y=popped.second;
                
                for (int i=0;i<4;i++)
                {
                    int nx=popped.first+directions[i][0],ny=popped.second+directions[i][1];
                    if (nx>=0 && nx<N && ny>=0 && ny<M && mat[nx][ny]!=-1)
                    {
                        ans[nx][ny]=depth;
                        mat[nx][ny]=-1;
                        q.push({nx,ny});
                    }
                }   
            }
            depth++;
        }
        return ans;
    }
};