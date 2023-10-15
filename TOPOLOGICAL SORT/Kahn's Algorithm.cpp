vector<int> topoSort(int V, vector<int> adj[]) 
{
    // Kahn's algorithm
    vector<int>indegree(V, 0);
    vector<int>res;
    int count = 0;
    
    for(int i = 0; i < V; i++) {
        for(int x: adj[i]) {
            indegree[x]++;
        }
    }
    
    queue<int>q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int frnt = q.front();
        q.pop();
        count++;
        res.push_back(frnt);
        for(int x: adj[frnt]) {
            indegree[x]--;
            if(indegree[x] == 0) q.push(x);
        }
    }
    
    if(count == V) return res;
    return {}; // invalid topogical sort i.e; not a DAG -> a cycle is present
}
