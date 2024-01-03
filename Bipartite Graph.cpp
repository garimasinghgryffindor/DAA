class Solution {
public:
    // using DFS
    bool dfs(vector<vector<int>>graph, int idx, vector<int>&colors, int color) {
        colors[idx] = color;
        
        for(int x: graph[idx]) {
            if(colors[x] == -1) {
                if(!dfs(graph, x, colors, !color)) return false;
            }
            else if(colors[x] == color) {
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>color(v, -1);
        
        for(int i=0 ; i<v ; i++) {
            if(color[i] == -1) {
                if(dfs(graph, i, color, 0) == false) return false;
            }
        }
        
        return true;
    }
};



class Solution {
public:
    // using BFS
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>colors(v, -1);
        queue<int>q;
        
        for(int i=0 ; i<v ; i++) {
            if(colors[i] != -1) continue;
            colors[i] = 0;
            q.push(i);
            
            while(!q.empty()) {
                int frnt = q.front();
                q.pop();
                int color = colors[frnt];

                for(int x: graph[frnt]) {
                    if(colors[x] == color) return false;
                    else if(colors[x] == -1) {
                        colors[x] = 1 - color;
                        q.push(x);
                    }
                }
            }
        }
        
        return true;
    }
};
