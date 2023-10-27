#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// This class represents a graph using adjacency list representation
class Graph {
  public:
    int V;         // no of vertices
    // adjacency list of the graph. adj[u] contains the list of pairs (v, w)
    // where
    //  v is a neighbour of u and w is the weight of the edge (u, v)
    vector<vector<pair<int, int>>> adj;
    Graph(int v) { // constructor
        V = v;
        // creates an adjacency list of size V+1, so that our vertices are
        // 1-indexed
        adj = vector<vector<pair<int, int>>>(V + 1);
    }
    // adds an edge from u to v, with weight w
    void addEdge(int u, int v, int w) { adj[u].push_back({v, w}); }
};
// Executes Dial's algorithm on the Graph g, and prints the shortest path
// from S to all other vertices. C is the maximum weight of any edge in the
// graph
void dialsAlgorithm(Graph g, int C, int S) {
    // The maximum number of buckets possible
    int maxBuckets = C * g.V;

    // buckets[i] stores all vertices that have a distance of i from S
    vector<unordered_set<int>> buckets(maxBuckets);

    // dist[i] stores the shortest distance from S to i
    //Initially, all distances are infinity or INT_MAX here.
    vector<int> dist(g.V + 1, INT_MAX);

    // initially, S is at distance 0 from itself
    dist[S] = 0;
    buckets[0].insert(S);

    // The current bucket that we are at in the algorithm
    int bucketPointer = 0;
    while (true) {
        // iterate through the buckets until we find a non-empty bucket, or run
        // out of buckets
        while (bucketPointer < maxBuckets && buckets[bucketPointer].empty()) {
            bucketPointer++;
        }

        // if we ran out of buckets, then we are done
        if (bucketPointer >= maxBuckets)
            break;

        // otherwise, we have found a non-empty bucket, and we will process it
        // We can choose any vertex. We will choose the first one.
        int v = *buckets[bucketPointer].begin();

        // remove v from the bucket, as we won't need it again.
        buckets[bucketPointer].erase(v);

        // iterate through all the neighbours of v
        for (pair<int, int> neiPair : g.adj[v]) {

            int nei = neiPair.first; // the neighbour
            int w = neiPair.second;  // the weight of the edge (v, nei)

            int altDist = dist[v] + w; // the distance from S to nei if we
                                       // travelled through v

            int currentDist = dist[nei]; // the current distance from S to nei

            // if we can improve the distance to nei by going through v, then we
            // will do so
            if (altDist < currentDist) {
                // if nei is not at infinity, it must be in some bucket. We will
                // remove it from that bucket
                if (currentDist != INT_MAX) {
                    buckets[currentDist].erase(nei);
                }

                // insert nei into the bucket that corresponds to its new
                // distance
                buckets[altDist].insert(nei);

                // update the distance to nei
                dist[nei] = altDist;
            }
        }
    }

    // print the shortest distances from S to all other vertices
    for (int i = 1; i <= g.V; i++) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 1; i <= g.V; i++) {
        cout << dist[i] << " ";
    }
    // And, we are done!
}
int main() {
    Graph g(6);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 2, 1);
    g.addEdge(3, 4, 4);
    g.addEdge(3, 5, 4);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 4, 3);
    g.addEdge(5, 6, 3);
    dialsAlgorithm(g, 4, 1);
    return 0;
}
