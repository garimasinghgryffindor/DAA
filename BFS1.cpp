//BFS

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

void addEdge(vector <list <int> > &graph , int s , int d)
{
    graph[s].push_back(d);
}

void bfs(vector <list <int> > &graph , int V , int start)
{
    vector <bool>  visited;
    visited.resize(V,false);

    queue <int> exploration_queue;
    visited[start]=true;

    exploration_queue.push(start);

    int vis;
    while(!exploration_queue.empty())
    {
        vis = exploration_queue.front();
        cout<<vis<<"  ";
        exploration_queue.pop();

        for(auto&it : graph[vis])
        {
            if(!visited[it])
            {
                visited[it] = true;
                exploration_queue.push(it);
            }
        }
    }
}

int main()
{
    int V,E,s,d;
    cout<<"Enter the number of vertices:  ";
    cin>>V;
    
    vector <list <int> > graph(V);
    cout<<"Enter the number of edges:  ";
    cin>>E;

    for(int i=0 ; i<E ; i++)
    {
        cout<<"Enter the source index:  ";
        cin>>s;
        cout<<"Enter the destination index:  ";
        cin>>d;
        
        addEdge(graph,s,d);
    }

    int start;
    cout<<"Enter the source node:  ";
    cin>>start;

    bfs(graph,V,start);

    return 0;
}