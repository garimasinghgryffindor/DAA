//GREEDY APPROACH TO FIND MINIMUM SPANNING TREE

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<pair<int , pair<int , int> > > viii;

class kruskals{
    viii graph , res;
    int V;
    int *parent;

    public:
    kruskals(viii graph,int V)
    {
        this->V=V;
        this->graph=graph;
        parent=new int[V];
        for(int i=0 ; i<V ; i++)
        {
            parent[i]=-1;
        }
    }

    int find(int x)
    {
        if(parent[x]<0)
            return x;

        return find(parent[x]);
    }

    void unionByWeight(int u , int v)
    {
        int pu = find(u), pv = find(v);

        if(pu!=pv)
        {
            if(parent[pv]<parent[pu])
            {
                parent[pv]+=parent[pu];
                parent[pu]=pv;
            }
            else{
                parent[pu]+=parent[pv];
                parent[pv]=pu;
            }
        }
    }

    void min_spanning_tree()
    {
        int s,d,w;
        int E=graph.size();

        sort(graph.begin(),graph.end());
        for(int i=0 ; i<E ; i++)
        {
            s = graph[i].second.first;
            d = graph[i].second.second;
            w = graph[i].first;

            if(find(s)!=find(d))
            {
                res.push_back(graph[i]);
                unionByWeight(s,d);
            }
        }
    }

    void print_tree()
    {
        int n=res.size();
        int cost=0;

        cout<<"S"<<"    "<<"D"<<"    "<<"W"<<endl;
        for(int i=0 ; i<n ; i++)
        {
            cost+=res[i].first;
            cout<<res[i].second.first<<"    "<<res[i].second.second<<"    "<<res[i].first<<endl;
        }
        cout<<"Tree Cost:  "<<cost<<endl;
        
    }
};

int main()
{   
    viii graph;
    int V,E,s,d,w;
    cout<<"Enter the number of vertices & Edges:  ";
    cin>>V>>E;
    for(int i=0 ; i<E ; i++)
    {
        cout<<"Enter the source, destination & weight for the edge:  "<<endl;
        cin>>s>>d>>w;
        graph.push_back(make_pair(w,make_pair(s,d)));
    }

    kruskals obj(graph,V);
    obj.min_spanning_tree();
    obj.print_tree();


    return 0;
}



// same
int find(vector<int>&parent, int x) {
    if(parent[x] < 0) return x;
    return find(parent, parent[x]);
}

void union_(vector<int>&parent, int u, int v) {
    int pu = find(parent, u), pv = find(parent, v);
    if(pu != pv) {
        if(parent[pu] <= parent[pv]) {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        } else {
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
    }
}

//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    // kruskals (GREEDY APPROACH)
    vector<pair<int, pair<int,int> > > graph;
    for(int i = 0; i < V; i++) {
        for(auto edge: adj[i]) {
            int u = i, v = edge[0], wt = edge[1];
            if(u > v) continue;
            graph.push_back({wt, {u,v}});
        }
    }
    
    sort(graph.begin(), graph.end());
    int cost = 0;
    vector<int>parent(V, -1);
    
    for(auto x: graph) {
        int u = x.second.first, v = x.second.second, wt = x.first;
        int pu = find(parent, u), pv = find(parent, v);
        if(pu != pv) {
            union_(parent, u, v);
            cost += wt;
        }
    }
    
    return cost;
}


