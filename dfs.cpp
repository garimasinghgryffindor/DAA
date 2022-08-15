#include <iostream>
#include <vector>
#include <list>

using namespace std;

void addEdge(vector<list <int> >&graph , int s , int d)
{
    graph[s].push_back(d);
}

void dfs(vector<list <int> >&graph , vector<bool>&visited , int start)
{
    visited[start]=true;
    cout<<start<<"  ";

    for(auto&it : graph[start])
    {
        if(!visited[it])
        {
            dfs(graph,visited,it);
        }
    }
}

int main()
{
    int V,E,s,d,start;
    cout<<"Enter the number of vertices:   ";
    cin>>V;
    vector <list <int> > graph(V);
    cout<<"Enter the number of Edges:  ";
    cin>>E;
    for(int i=0 ; i<E ; i++)
    {
        cout<<"Enter the source node :  ";
        cin>>s;
        cout<<"Enter the destination node :  ";
        cin>>d;
        addEdge(graph,s,d);
    }

    vector <bool> visited(V);
    visited.resize(V,false);
    cout<<"Enter the source node:  ";
    cin>>start;
    dfs(graph,visited,start);

    return 0;
}