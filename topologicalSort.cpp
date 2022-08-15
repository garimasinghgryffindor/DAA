#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topologicalSortUtils(vector<int>graph[],bool visited[],stack<int>&st,int i)
{
    visited[i]=true;
    int n=graph[i].size();
    for(int j=0 ; j<n ; j++)
    {
        if(!visited[graph[i][j]])
        {
            topologicalSortUtils(graph,visited,st,graph[i][j]);
        }
    }
    st.push(i);
}

void topologicalSort(vector<int>graph[],int V)
{
    bool visited[V];
    stack <int> st;
    for(int i=0 ; i<V ; i++)
    {
        visited[i]=false;
    }

    for(int i=0 ; i<V ; i++)
    {
        if(!visited[i])
        {
            topologicalSortUtils(graph,visited,st,i);
        }
    }

    while(!st.empty())
    {
        cout<<st.top()+1<<"  ";
        st.pop();
    }
}

int main()
{
    int V,E,s,d;
    cout<<"Enter the number of vertices:  ";
    cin>>V;
    cout<<"Enter the number of edges:  ";
    cin>>E;
    vector <int> graph[V];
    
    for(int i=0 ; i<E ; i++)
    {   
        cout<<"Enter the source vertex:  ";
        cin>>s;
        cout<<"Enter the destination vertex:  ";
        cin>>d;
        graph[s].push_back(d);
    }

    topologicalSort(graph,V);

    return 0;
}