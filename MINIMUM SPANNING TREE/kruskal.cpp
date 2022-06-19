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

