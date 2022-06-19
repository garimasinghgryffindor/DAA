//  TRIANGLE INEQUALITY

#include <iostream>
#include <vector>
using namespace std;

int min(int x,int y)
{
    if(x<=y)
        return x;
    return y;
}

int TSP(vector<vector<int> > graph , int S , int V)
{
    vector <int> vertex;

    for(int i=0 ; i<V ; i++)
    {
        if(i!=S)
        {
            vertex.push_back(i);
        }
    }

    int min_path = INT_MAX;

    do{
        int current_path_wt = 0;
        int k = S;
        
        for(int i=0 ; i<vertex.size() ; i++)
        {
            current_path_wt+=graph[k][vertex[i]];
            k=vertex[i];
        }
        current_path_wt+=graph[k][S];
        min_path = min(min_path,current_path_wt);
    }while(next_permutation(vertex.begin(),vertex.end()));

    return min_path;
}

int main()
{   
    int V,E,s,d;
    cout<<"Enter the number of vertices:  ";
    cin>>V;
    vector<vector <int> > graph(V , vector<int>(V,0));

    cout<<"Enter the number of edges:   ";
    cin>>E;

    for(int i=0 ; i<E ; i++)
    {
        cout<<"Enter the source and destination:  ";
        cin>>s>>d;
        int wt;
        cout<<"Enter the weight of the edge:  ";
        cin>>wt;
        graph[s][d]=wt;
        graph[d][s]=wt;
    }
    cout<<"Enter the starting point:  ";
    int S;
    cin>>S;

    int cost  = TSP(graph,S,V);

    cout<<cost<<endl;

    return 0;
}
