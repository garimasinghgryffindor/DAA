#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 100
using namespace std;

struct Node {
    char c;
    int freq;
    Node *left, *right;
};

void heapify(Node * arr[], int n,int i) {
    int c1 = 2*i + 1;
    int c2 = 2*i + 2;
    int min = i;
    if(c1<n && arr[c1]->freq < arr[min]->freq) {
        min = c1;
    }
    if(c2<n && arr[c2]->freq < arr[min]->freq) {
        min = c2;
    }

    if(min != i) {
        //swap
        auto temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void buildHeap(Node *arr[], int n) {
    for(int i=n/2-1 ; i>=0 ; i--) {
        heapify(arr,n,i);
    }
}

Node * extractMin(Node *arr[], int&n) {
    Node * res = arr[0];

    //swap arr[last] with arr[first]
    Node * temp = arr[0];
    arr[0] = arr[n-1];
    arr[n-1] = temp;

    n--;

    heapify(arr,n,0);

    return res;
}

void percolateUp(Node *arr[], int n, int i) {
    int parent = (i-1)/2;
    if(i == 0 || arr[parent]->freq <= arr[i]->freq)
        return ;
    
    Node * temp = arr[i];
    arr[i] = arr[parent];
    arr[parent] = temp;

    percolateUp(arr,n,parent);
}

void insert(Node*arr[], int&n, Node *node) {
    arr[n] = node;
    n++;
    percolateUp(arr,n,n-1);
}

void print(Node* node, string s) {
    if(node->c != '$') {
        // i.e; a leaf node
        // an actual character
        cout<<node->c<<" "<<s<<endl;
        return;
    }

    print(node->left,s+"0");
    print(node->right,s+"1");
}

int main()
{
    int n = 0;

    // taking input
    cout<<"Enter the number of characters to be encoded:  ";
    cin>>n;
    Node * arr[MAX];

    for(int i=0 ; i<n ; i++) {
        char ch;
        int freq;
        cout<<"Enter the character:   ";
        cin>>ch;
        cout<<"Enter the frequency of the character:   ";
        cin>>freq;
        Node * node = new Node();
        node->c = ch;
        node->freq = freq;
        node->left = node->right = NULL;
        arr[i] = node;
    }

    // building min heap
    // function call
    buildHeap(arr,n);

    while(n!=1) {
        Node *min1 = extractMin(arr,n) , *min2 = extractMin(arr,n), *min3;

        min3 = new Node();
        min3->c = '$';
        min3->freq = min1->freq + min2->freq;
        min3->left = min1;
        min3->right = min2;
        insert(arr,n,min3);
    }

    cout<<endl;
    print(arr[0],"");

    return 0;
}
