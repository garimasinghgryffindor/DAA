bool dfs(vector<int>adj[], vector<int>&vis, int pos,int parent) {
    vis[pos] = true;
    
    for(int x: adj[pos]) {
        if(!vis[x]) {
            if(dfs(adj, vis, x, pos)) return true;
        } else if(x != parent) {
            return true;
        }
    }
    
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int>vis(V, false);
    
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(dfs(adj, vis,i,-1)) return true;
        }
    }
    return false;
}
