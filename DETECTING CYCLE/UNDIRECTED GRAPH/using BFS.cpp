bool isCycle(int V, vector<int> adj[]) {
    vector<int>vis(V, false);
    queue<pair<int,int>> q;
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            q.push({i,-1});
            vis[i] = true;
            
            while(!q.empty()) {
                int nodex = q.front().first;
                int parent = q.front().second;
                q.pop();
                
                // vis[nodex] = true;
            
                for(int x: adj[nodex]) {
                    if(!vis[x]) {
                        vis[x] = true;
                        q.push({x, nodex});
                    } else if(x != parent) return true;
                }
            }
        }
    }
    
    return false;
}
