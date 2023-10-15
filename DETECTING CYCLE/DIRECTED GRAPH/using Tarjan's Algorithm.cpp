bool utils(vector<int>adj[],vector<int>&disc,vector<int>&low,vector<bool>&vis,stack<int>&st,int pos) {
    static int timer = 0;
    timer++;
    disc[pos] = low[pos] = timer;
    st.push(pos);
    vis[pos] = true;
    
    for(int x: adj[pos]) {
        if(disc[x] == -1) {
            if(utils(adj, disc, low, vis, st, x)) return true;
            low[pos] = min(low[pos], low[x]);
        } else if(vis[x]) {
            low[pos] = min(low[pos], disc[x]);
        }
    }
    
    if(low[pos] == disc[pos]) {
        int count = 0;
        while(st.top() != pos) {
            int tp = st.top();
            st.pop();
            vis[tp] = false;
            count++;
        }
        int tp = st.top();
        st.pop();
        vis[tp] = false;
        count++;
        if(count > 1) return true;
    }
    
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    // vector<vector<int>>res;
    vector<int>disc(V, -1);
    vector<int>low(V, -1);
    vector<bool>vis(V, false);
    stack<int>st;
    
    for(int i = 0; i < V; i++) {
        if(disc[i] == -1) {
            if(utils(adj, disc, low, vis, st, i)) return true;
        }
    }
    return false;
}
