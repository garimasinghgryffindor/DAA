//GREEDY APPROACH TO FIND MINIMUM SPANNING TREE

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class prims{
    int *parent,*weights;
    bool *mst_set;
    int V;
    vector <vector <int> > graph;
    public:

    prims(vector <vector<int> > &graph, int V)
    {
        this->graph=graph;
        this->V=V;
        parent = new int[V];
        weights = new int[V];
        mst_set = new bool[V];
        for(int i=0 ; i<V ; i++)
        {
            parent[i]=-1;
            weights[i]=INT_MAX;
            mst_set[i]=false;
        }
    }

    int min_weight_index()
    {
        int min=-1;
        int min_weight=INT_MAX;
        for(int i=0 ; i<V ; i++)
        {
            if(mst_set[i]==false && weights[i]<min_weight)
            {
                min=i;
                min_weight=weights[i];
            }
        }

        return min;
    }

    void min_spanning_tree()
    {
        weights[0]=0;

        for(int i=0 ; i<V-1 ; i++)
        {
            int min_index = min_weight_index();
            mst_set[min_index]=true;
            
            for(int i=0 ; i<V ; i++)
            {
                if(graph[min_index][i] && mst_set[i]==false && graph[min_index][i]<weights[i])
                {
                    parent[i] = min_index;
                    weights[i] = graph[min_index][i];
                }
            }
        }

    }

    void print_tree()
    {
        int cost=0;
        cout<<"S    D    W"<<endl;
        for(int i=1 ; i<V ; i++)
        {
            cost+=weights[i];
            cout<<parent[i]<<"    "<<i<<"    "<<weights[i]<<endl;
        }

        cout<<"Minimum Spanning Tree Cost:  "<<cost<<endl;
    }

};

int main()
{
    int V,E,s,d,w;
    
    cout<<"Enter the number of Vertices & Edges:";
    cin>>V>>E;
    vector <vector <int> > graph(V, vector <int> (V, 0));

    for(int i=0 ; i<E ; i++)
    {
        cout<<"Enter the source, destination and weight:  ";
        cin>>s;
        cin>>d;
        cin>>w;
        graph[s][d]=w;
        graph[d][s]=w;
    }

    prims obj(graph,V);
    obj.min_spanning_tree();
    obj.print_tree();

    return 0;
}