#include <iostream>
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
        if(parent[x-1]<0)
            return x;
        
        return find(parent[x-1]);
    }

    void unionByWeight(int u,int v)
    {
        int pu=find(u),pv=find(v);
        
        if(pu!=pv)
        {
            if(parent[pv-1]<parent[pu-1])
            {
                parent[pv-1]+=parent[pu-1];
                parent[pu-1]=pv;
            }

            else
            {
                parent[pu-1]+=parent[pv-1];
                parent[pv-1]=pu;
            }
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
    obj.unionByWeight(1,2);
    obj.unionByWeight(3,4);
    obj.unionByWeight(5,6);
    obj.unionByWeight(7,8);
    obj.unionByWeight(2,4);
    obj.unionByWeight(2,5);
    obj.unionByWeight(1,3);
    obj.unionByWeight(6,8);
    obj.unionByWeight(5,7);

    obj.print();

    return 0;
}

