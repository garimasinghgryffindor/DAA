void utils(vector<int>adj[],vector<int>&disc,vector<int>&low,vector<bool>&vis,stack<int>&st,int pos, vector<vector<int>>&res) {
    static int timer = 0;
    timer++;
    disc[pos] = low[pos] = timer;
    vis[pos] = true;
    st.push(pos);
    
    for(int x: adj[pos]) {
        if(disc[x] == -1) {
            // go visit it
            utils(adj,disc,low,vis,st,x,res);
            low[pos] = min(low[pos], low[x]);
        } else if(vis[x] == true) {
            // back edge
            low[pos] = min(low[pos], disc[x]);
        }
    }
    
    
    if(disc[pos] == low[pos]) {
        // root node
        vector<int>temp;
        while(st.top() != pos) {
            int tp = st.top(); st.pop();
            vis[tp] = false;
            temp.push_back(tp);
        }
        int tp = st.top(); st.pop();
        vis[tp] = false;
        temp.push_back(tp);
        sort(temp.begin(), temp.end());
        res.push_back(temp);
    }
}

vector<vector<int>> tarjans(int V, vector<int> adj[])
{
    vector<vector<int>>res;
    vector<int>disc(V, -1);
    vector<int>low(V, -1);
    vector<bool>vis(V, false);
    stack<int>st;
    
    for(int i = 0; i < V; i++) {
        if(disc[i] == -1) utils(adj, disc, low, vis, st, i, res);
    }
    
    sort(res.begin(), res.end());
    return res;
}
