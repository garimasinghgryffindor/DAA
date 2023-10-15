bool isCyclic(int V, vector<int> adj[]) {
    // using bfs
    // using Kahn's algo
    vector<int>indegree(V, 0);
    int count = 0;
    for(int i = 0; i < V; i++) {
        for(int x: adj[i]) {
            indegree[x]++;
        }
    }
    
    queue<int>q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    
    while(!q.empty()) {
        int frnt = q.front();
        q.pop();
        count++;
        for(int x: adj[frnt]) {
            indegree[x]--;
            if(indegree[x] == 0) {
                q.push(x);
            }
        }
    }
    
    if(count == V) return false;
    return true;
}
