void topo(vector<int>adj[], vector<bool>&vis,stack<int>&st, int pos) {
    vis[pos] = true;
    
    for(int x: adj[pos]) {
        if(!vis[x]) topo(adj, vis, st, x);
    }
    st.push(pos);
}

void dfs(vector<int>adj[], int pos, vector<int>&res, vector<bool>&vis) {
    vis[pos] = true;
    res.push_back(pos);
    
    for(int x: adj[pos]) {
        if(!vis[x]) {
            dfs(adj, x, res, vis);
        }
    }
}

bool isCyclic(int V, vector<int> adj[]) {
   // using Kosaraju's algorithm
   // if any strongly-connected component has more than 1 node -> means a cycle
   stack<int>track;
   vector<bool>vis(V, false);
   for(int i = 0; i < V; i++) {
       if(!vis[i]) topo(adj, vis, track, i);
   }
   
   // transpose
   vector<int>adj2[V];
   for(int i = 0; i < V; i++) {
       for(int x: adj[i]) {
           adj2[x].push_back(i);
       }
   }
   
   vector<bool>visited(V, false);
   while(!track.empty()) {
       int tp = track.top(); track.pop();
       if(!visited[tp]) {
           vector<int>temp;
           dfs(adj2, tp, temp, visited);
           if(temp.size() > 1) return true;
       }
   }
   return false;
}

// important
