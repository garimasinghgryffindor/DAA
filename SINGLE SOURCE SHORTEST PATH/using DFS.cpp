void dfs(vector<int>adj[],vector<int>&res,vector<bool>&vis, int src, int wt) {
        vis[src] = true;
        
        for(int x: adj[src]) {
            if(!vis[x]) {
                res[x] = min(res[x], 1+wt);
                dfs(adj,res,vis,x,1+wt);
            }
        }
        
        vis[src] = false;
    }
    
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // using DFS
        vector<int>res(N,INT_MAX);
        vector<bool>vis(N, false);
        queue<int>q;
        vector<int>adj[N];
        for(int i = 0; i < M; i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        res[src] = 0;
        dfs(adj, res, vis, src, 0);
        
        for(int i = 0; i < N; i++) {
            if(res[i] == INT_MAX) {
                res[i] = -1;
            }
        }
        
        return res;
    }
