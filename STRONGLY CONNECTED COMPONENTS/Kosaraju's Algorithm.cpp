void topo(vector<vector<int>>&adj,int pos,vector<bool>&vis,stack<int>&st) {
    vis[pos] = true;
    for(int x: adj[pos]) {
        if(!vis[x]) {
            topo(adj,x,vis,st);
        }
    }
    st.push(pos);
}

void dfs(vector<int>adj[], int pos, vector<bool>&vis) {
    vis[pos] = true;
    for(int x: adj[pos]) {
        if(!vis[x]) dfs(adj,x,vis);
    }
}

int kosaraju(int V, vector<vector<int>>& adj)
{
    int count = 0;
    stack<int>track;
    vector<bool>vis(V, false);
    // sorting in order of finishing time
    for(int i = 0; i < V; i++) {
        if(!vis[i]) topo(adj, i,vis,track);
    }
    
    // graph transpose
    vector<int>transpose[V];
    for(int i = 0; i < V; i++) {
        for(int x: adj[i]) 
            transpose[x].push_back(i);
    }
    
    vector<bool>visited(V, false);
    
    while(!track.empty()) {
        // cout<<"hello\n";
        int tp = track.top(); track.pop();
        if(!visited[tp]) {
            // cout<<"hello again\n";
            count++;
            dfs(transpose, tp, visited);
        }
    }
    return count;
}


