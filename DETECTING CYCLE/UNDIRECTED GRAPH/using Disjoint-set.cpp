int find(vector<int> parent, int x) {
    if(parent[x] < 0) return x;
    return find(parent, parent[x]);
}

void union_(vector<int>&parent, int u, int v) {
    int pu = find(parent, u), pv = find(parent, v);
    if(parent[pu] <= parent[pv]) {
        // pu more negative
        parent[pu] += parent[pv];
        parent[pv] = pu;
    } else {
        // pv more negative
        parent[pv] += parent[pu];
        parent[pu] = pv;
    }
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int>parent(V, -1);
    for(int i = 0; i < V; i++) {
        for(int x: adj[i]) {
            int u = i, v = x;
            if(u > v) continue;
            int pu = find(parent, u), pv = find(parent, v);
            if(pu == pv) return true;
            union_(parent, u, v);
        }
    }
    
    return false;
}
