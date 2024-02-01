#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int const N = 5e4 + 1;

struct node {
	int sum, res, pre, suf;
	node() {}
	node(int val) {
		sum = res = pre = suf = val;
	}
};

node tree[N * 4];

node merge(node left, node right) {
	node ret;
	ret.sum = left.sum + right.sum;
	ret.pre = max(left.pre, left.sum + right.pre);
	ret.suf = max(right.suf, right.sum + left.suf);
	ret.res = max(left.res, max(right.res, left.suf + right.pre));
	return ret;
}

void buildTree(int arr[], int idx, int l, int r) {
    if(l > r) return;
    
    if(l == r) {
        tree[idx] = node(arr[l]);     return;
    }
    
    int mid = l + (r-l)/2;
    buildTree(arr, 2*idx+1, l, mid);
    buildTree(arr, 2*idx+2, mid+1, r);
    
    tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
}

void constructST(int arr[],int n)
{
    // int num_elements = 2*n - 1;
    // int temp = ceil(log2(num_elements));
    // int len = pow(2, temp) - 1;
    
    // node tree[len];
    int idx = 0, l = 0, r = n-1;
    
    buildTree(arr, idx, l , r);
    
}

 
 node query(int ql, int qr, int idx, int l, int r) {
     if(ql > r || qr < l) return node(-1000000);
     
     if(l >= ql && r <= qr) {
         return tree[idx];
     }
     
     int mid = l + (r-l)/2;
     
     node left = query(ql, qr, 2*idx+1, l, mid);
     node right = query(ql, qr, 2*idx+2, mid+1, r);

    return merge(left, right);
 }
 
int RMQ(int n, int a, int b)
{
    int idx = 0;
    int l = 0, r = n-1;
    node ans = query(a, b, idx, l, r);
    return ans.res;
}


int main()
{
    int n;  cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    constructST(arr, n);

    int q;  cin>>q;
    vector<int>res;
   
    for(int i = 0; i < q; i++) {
        int l, r;
        cin>>l;
        cin>>r;
        int ans = RMQ(n, l-1, r-1);
        res.push_back(ans);
    }

    for(int x: res) {
        cout<<x<<endl;
    }

    return 0;
}
