// ONLY FOR UNWEIGHTED GRAPH
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    // using BFS
    vector<int>res(N,INT_MAX);
    vector<bool>vis(N, false);
    queue<int>q;
    vector<int>adj[N];
    for(int i = 0; i < M; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    q.push(src);
    res[src] = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int node = q.front(); q.pop();
            if(vis[node]) continue;
            vis[node] = true;
            for(int x: adj[node]) {
                if(res[node] + 1 < res[x]) {
                    res[x] = res[node] + 1;
                }
                q.push(x);
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        if(res[i] == INT_MAX) res[i] = -1;
    }
    
    return res;
}



