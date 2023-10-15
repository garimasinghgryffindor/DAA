//GREEDY ALGORITHM TO FIND THE SHORTEST PATH FROM THE SOURCE NODE,  ALTHOUGH MAY/MAY NOT WORK IF THERE IS A NEGATIVE WEIGHTED EDGE

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef vector<pair<int , int> > vii;

class dijkstras{
    vector <vector <int> > graph;
    int V,source;
    vii shortest_path;
    bool *set;

    public:

    dijkstras(vector <vector <int> >&graph,int V)
    {
        this->graph=graph;
        this->V=V;
        
        for(int i=0 ; i<V ; i++)
        {
            shortest_path.push_back(make_pair(i, INT_MAX));
        }

        set = new bool[V];
        for(int i=0 ; i<V ; i++)
        {
            set[i]=false;
        }
    }

    int min_weight_so_far_not_including_already_set()
    {
        int min=INT_MAX,min_index=-1;
        for(int i=0 ; i<V ; i++)
        {
            if(set[i]==0 && shortest_path[i].second<min)
            {
                min=shortest_path[i].second;
                min_index=i;
            }
        }

        return min_index;
    }

    void shortestPath(int source)
    {
        this->source=source;
        shortest_path[source].second=0;

        for(int j=0 ; j<V ; j++)
        {
            int u=min_weight_so_far_not_including_already_set();

            set[u]=true;
            for(int i=0 ; i<V ; i++)
            {
                int chk = graph[u][i];
                if(chk!=0 && set[i]==false)
                {
                    int wt = shortest_path[u].second + chk;
                    if(wt<shortest_path[i].second)
                    {
                        shortest_path[i].second = wt;
                    }
                }
            }
        }

        print_dijkstra();

    }

    void print_dijkstra()
    {
        cout<<"Vertex      "<<"Distance from Source"<<endl;
        for(int i=0 ; i<V ; i++)
        {
            cout<<shortest_path[i].first<<"           "<<shortest_path[i].second<<endl;
        }
    }

};

int main()
{
    int V,E,s,d,w;
    int source;

    cout<<"Enter the number of Vertices and Edges:  ";
    cin>>V>>E;
    vector <vector <int> > graph(V, vector <int> (V,0));
    for(int i=0 ; i<E ; i++)
    {
        cout<<"Enter the source, destination & weight :  ";
        cin>>s>>d>>w;
        graph[s][d]=w;
    }

    cout<<"Enter the source vertex:  ";

    dijkstras obj(graph,V);
    cin>>source;    
    obj.shortestPath(source);

    return 0;
}


// using PRIORITY QUEUE
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int>res(V, INT_MAX);
    vector<bool>set(V, false);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,S});
    while(!pq.empty()) {
        int node = pq.top().second, wt = pq.top().first;
        pq.pop();
        if(set[node]) continue;
        set[node] = true;
        res[node] = wt;
        for(auto x: adj[node]) {
            int nd = x[0], w = x[1];
            pq.push({wt+w, nd});
        }
    }
    return res;
}

// USING PRIORITY QUEUE (explicit relaxation)
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>res(V, INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,S});
        res[S] = 0;
        
        while(!pq.empty()) {
            int node = pq.top().second, wt = pq.top().first;
            pq.pop();
            
            for(auto x: adj[node]) {
                int nd = x[0], w = x[1];
                // RELAXATION
                if(res[nd] > wt + w) {
                    res[nd] = wt + w;
                    pq.push({wt+w, nd});
                }
            }
        }
        return res;
    }
