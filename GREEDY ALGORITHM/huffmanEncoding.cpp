//  HUFFMAN ENCODING

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef struct nodetype{
    char c;
    int freq;
    struct nodetype *left,*right;
}node;

void heapify(node* arr[],int n,int i)
{
    int c1 = 2*i+1;
    int c2 = 2*i+2;

    int min = i;

    if(c1<n && arr[c1]->freq < arr[min]->freq)
    {
        min = c1;
    }

    if(c2<n && arr[c2]->freq < arr[min]->freq)
    {
        min = c2;
    }

    if(min!=i)
    {
        node* temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;

        heapify(arr,n,min);
    }
}

void buildHeap(node* arr[],int n)
{
    for(int i=n/2-1 ; i>=0 ; i--)
    {
        heapify(arr,n,i);
    }
}

node * extract_min(node* arr[] , int &n)
{
    node* temp = arr[0];
    arr[0] = arr[n-1];
    arr[n-1] = temp;
    node * ret = arr[n-1];
    n--;

    heapify(arr,n,0);
    return ret;
}

void percolate_up(node * arr[] , int n , int i)
{
    int parent = (i-1)/2;
    if(i==0 || arr[parent]->freq > arr[i]->freq)
        return;
    
    node *temp = arr[i];
    arr[i] = arr[parent];
    arr[parent] = temp;
    percolate_up(arr,n,parent);
}

void insert(node *arr[] , int &n , node * element)
{
    arr[n] = element;
    n++;
    percolate_up(arr,n,n-1);
}

void print(node * root , string s)
{
    if(root->c != '$')
    {
        cout<<root->c<<"  "<<s<<endl;
        return;
    }
    print(root->left,s+'0');
    print(root->right,s+'1');
}


int main()
{
    int n, count;
    char c;
    cout<<"Enter the number of character to be coded:  ";
    cin>>n;

    node* arr[n];

    for(int i=0 ; i<n ; i++)
    { 
        cout<<"Enter the character: ";
        cin>>c;
        cout<<"Enter the frequency of the character:  ";
        cin>>count;
        arr[i] = new node();
        arr[i]->c = c;
        arr[i]->freq = count;
        arr[i]->left=arr[i]->right = NULL;
    }

    buildHeap(arr,n);

    while(n!=1)
    {
        node * he1 = extract_min(arr,n) , * he2 = extract_min(arr,n) , *he3;
        he3 = new node();
        he3->c = '$';
        he3->freq = he1->freq + he2->freq;
        he3->left = he1;
        he3->right = he2;
        insert(arr,n,he3);
    }

    print(arr[0] , "");

    return 0;
}


/*
    a            5
    b           9
    c           12
    d           13
    e           16
    f           45
*/