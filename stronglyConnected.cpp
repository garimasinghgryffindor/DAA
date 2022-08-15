#include <iostream>
#include <vector>
using namespace std;

class Disjoint{
    int n;
    int *parent;

    public:

    Disjoint(int n)
    {
        this->n=n;
        parent  = new int[n];
        for(int i=0 ; i<n ; i++)
        {
            parent[i] = -1;
        }
    }

    int find(int x)
    {
        if(parent[x]<0)
            return x;
        
        return find(parent[x]);
    }

    void unionByWeight(int u,int v)
    {
        int pu=find(u),pv=find(v);
        
        if(pu!=pv)
        {
            if(parent[pv]<parent[pu])
            {
                parent[pv]+=parent[pu];
                parent[pu]=pv;
            }

            else
            {
                parent[pu]+=parent[pv];
                parent[pv]=pu;
            }
        }
    }

    void stronglyConnected()
    {
        vector <int> parents;
        int m=0;

        for(int i=0 ; i<n ; i++)
        {
            if(parent[i]<0)
            {
                m++;
                parents.push_back(i);
            }
        }

        vector<vector<int> > connectedSets(m) ;
    
        for(int i=0 ; i<m ; i++)
        {
            int main_parent=parents[i];

            for(int j=0 ; j<n ; j++)
            {
                if(find(j)==main_parent)
                {
                    connectedSets[i].push_back(j);
                }
            }
        }

        for(int i=0 ; i<m ; i++)
        {
            cout<<"Set:  "<<i+1<<endl;
            for(auto&it: connectedSets[i])
            {
                cout<<it<<"  ";
            }
            cout<<endl<<endl;
        }
    }

    void print()
    {
        cout<<"[  ";
        for(int i=0 ; i<n ; i++)
        {
            cout<<parent[i]<<"  ";
        }
        cout<<"]"<<endl;
    }

};

int main()
{
    int n=8;
    Disjoint obj(n);
    obj.unionByWeight(1,0);
    obj.unionByWeight(0,2);
    obj.unionByWeight(4,3);
    obj.unionByWeight(3,5);
    obj.unionByWeight(6,7);
    // obj.unionByWeight(2,5);
    // obj.unionByWeight(1,3);
    // obj.unionByWeight(6,8);
    // obj.unionByWeight(5,7);

    obj.print();
    obj.stronglyConnected();

    return 0;
}

