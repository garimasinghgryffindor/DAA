bool dfs(vector<int>adj[],int pos,vector<bool>&vis,vector<bool>&st) {
    vis[pos] = true;
    st[pos] = true;
    for(int x: adj[pos]) {
        if(!vis[x]) {
            if(dfs(adj, x, vis, st)) return true;
        } else if(st[x]) {
            return true;
        }
    }
    
    st[pos] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    // code here
    // using dfs
    vector<bool>vis(V, false), st(V, false);
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(dfs(adj,i,vis,st)) return true;
        }
    }
    
    return false;
}

