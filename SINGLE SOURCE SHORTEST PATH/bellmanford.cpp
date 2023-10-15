// DYNAMIC PROGRAMMING TO FIND THE SHORTEST PATH FROM THE SOURCE NODE, WORK IF THERE IS A NEGATIVE WEIGHTED EDGE
//  BUT SOMETIMES THERE MAY BE NEGATIVE WEIGHT CYCLE, THIS ALGO CANNOT WORK FOR THAT, BUT IT CAN DETECT A CYCLE.

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef vector<pair<int, int> > vii;
typedef vector<pair<int, pair<int, int> > > viii;

class bellman
{
    viii graph;
    int V;
    vii shortest_path;
    int source;

public:
    bellman(viii &graph, int V)
    {
        this->graph = graph;
        this->V = V;

        for (int i = 0; i < V; i++)
        {
            shortest_path.push_back(make_pair(i, INT_MAX));
        }
    }

    void shortestPath(int source)
    {
        int edges_size = graph.size();
        this->source = source;
        shortest_path[source].second = 0;

        for (int j = 0; j < V - 1; j++)
        {
            for (int i = 0; i < edges_size; i++)
            {
                int u = graph[i].second.first, v = graph[i].second.second;
                int wt = graph[i].first;
                int present_cost = shortest_path[u].second + wt;

                if(shortest_path[u].second!=INT_MAX)
                if (present_cost < shortest_path[v].second)
                {
                    shortest_path[v].second = present_cost;
                }
            }
        }

        int cycle=-1;
        for (int i = 0; i < edges_size; i++)
        {
            int u = graph[i].second.first, v = graph[i].second.second;
            int wt = graph[i].first;
            int present_cost = shortest_path[u].second + wt;

            if (present_cost < shortest_path[v].second)
            {
                cycle=1;
                cout<<"Negative cycle exists"<<endl;
                break;
            }
        }

        print_bellman();
    }

    void print_bellman()
    {
        cout << "Vertex      "
             << "Distance from Source" << endl;
        for (int i = 0; i < V; i++)
        {
            cout << shortest_path[i].first << "           " << shortest_path[i].second << endl;
        }
    }
};

int main()
{
    viii graph;
    int V, E, s, d, w;
    int source;
    cout << "Enter the number of vertices & Edges:  ";
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        cout << "Enter the source, destination & weight for the edge:  " << endl;
        cin >> s >> d >> w;
        graph.push_back(make_pair(w, make_pair(s, d)));
    }

    cout << "Enter the source vertex:  ";

    bellman obj(graph, V);
    cin >> source;
    obj.shortestPath(source);

    return 0;
}


// //
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    // take all the edges
    // relax them V-1 times
    vector<int>res(V, INT_MAX);
    res[S] = 0;
    
    for(int i = 0; i < V-1; i++) {
        for(auto edge: edges) {
            int u = edge[0], v = edge[1], cost = edge[2];
            
            if(res[u] != INT_MAX && res[v] > res[u] + cost) {
                res[v] = res[u] + cost;
            }
        }
    }
    
    for(auto edge: edges) {
        int u = edge[0], v = edge[1], cost = edge[2];
        if(res[u] == INT_MAX) continue;
        if(res[v] > res[u] + cost) {
            return {-1};
        }
    }
    
    for(int i = 0; i < V; i++) {
        if(res[i] == INT_MAX) {
            res[i] = 100000000;
        }
    }
    
    return res;
}
