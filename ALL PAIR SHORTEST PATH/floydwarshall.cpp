//DYNAMIC PROGRAMMING APPROACH TO FIND ALL PAIR SHORTEST PATH

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class floyd{
    int V;
    vector <vector <int> > graph , res;
    public:

    floyd(vector <vector <int> > &graph , int V)
    {
        this->graph=graph;
        this->res=graph;
        this->V=V;
    }

    void allPairShortest(){
        for(int i=0 ; i<V ; i++)
        {
            for(int j=0 ; j<V ; j++)
            {
                for(int k=0 ; k<V ; k++)
                {
                    if(res[i][j]>res[i][k]+res[k][j] && res[i][k]!=INT_MAX && res[k][j]!=INT_MAX)
                    {
                        res[i][j]=res[i][k]+res[k][j];
                    }
                }
            }
        }


        //PRINTING THE ALL PAIR SHORTEST PATH TABLE
        cout<<endl;
        cout<<"   ";
        for(int i=0 ; i<V ; i++)
        {
            cout<<"    "<<i;
        }
        cout<<endl;
        for(int i=0 ; i<V ; i++)
        {
            cout<<i<<"   |  ";
            for(int j=0 ; j<V ; j++)
            {
                if(res[i][j]==INT_MAX)
                {
                    cout<<"INF  ";
                }
                else
                cout<<res[i][j]<<"    ";
            }
            cout<<"|"<<endl;
        }
    }

};

int main()
{
    int V,E,s,d,w;
    int source;

    cout<<"Enter the number of Vertices and Edges:  ";
    cin>>V>>E;
    vector <vector <int> > graph(V, vector <int> (V,INT_MAX));
    for(int i=0 ; i<E ; i++)
    {
        cout<<"Enter the source, destination & weight :  ";
        cin>>s>>d>>w;
        graph[s][d]=w;
    }

    floyd obj(graph,V);   
    obj.allPairShortest();

    return 0;
}

// // // // // // // // // // // // // // // // // // // // // // // // // 
// // // // // // // // // // // // // // // // // // // // // // // // // 
// // // // // // // // // // // // // // // // // // // // // // // // // 
void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e9;
	            }
	            if(i==j){
	                matrix[i][j]=0;
	            }
	        }
	    }
	    
	    for(int k = 0; k < n; k++) {
	        for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
	        }
	    }
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j]==1e9){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	}
