// MIN HEAP

#include <iostream>
#define MAX 100
using namespace std;

void heapify(int arr[],int n,int i)
{
    int c1 = 2*i+1;
    int c2 = 2*i+2;

    int min = i;

    if(c1<n && arr[c1]<arr[min])
    {
        min = c1;
    }

    if(c2<n && arr[c2]<arr[min])
    {
        min = c2;
    }

    if(min!=i)
    {
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;

        heapify(arr,n,min);
    }
}

void buildHeap(int arr[],int n)
{
    for(int i=n/2-1 ; i>=0 ; i--)
    {
        heapify(arr,n,i);
    }
}

void extract_min(int arr[] , int n)
{
    int temp = arr[0];
    arr[0] = arr[n-1];
    arr[n-1] = temp;
    n--;

    buildHeap(arr,n);
}

int main()
{
    int n;
    int arr[MAX];
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    cout<<"Enter the elements:\n";
    for(int i =0 ; i<n ; i++)
    {
        cin>>arr[i];
    }

    buildHeap(arr,n);

    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    extract_min(arr,n);

    for(int i=0 ; i<n-1 ; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    return 0;
}