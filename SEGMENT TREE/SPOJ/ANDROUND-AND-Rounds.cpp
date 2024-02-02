#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
#define vi vector<int>
using namespace std;

vi tree;

void buildTree(vi&vec, int idx, int l, int r) {
    if(l > r) return;
    if(l == r) {
        tree[idx] = vec[l];     return;
    }

    int mid = l + (r-l)/2;
    buildTree(vec, 2*idx+1, l, mid);
    buildTree(vec, 2*idx+2, mid+1, r);
    tree[idx] = tree[2*idx+1] & tree[2*idx+2];
}

int query(int idx, int l, int r, int&ql, int&qr) {
    if(l > r || qr < l || ql > r) return 2147483647;
    if(ql <= l && qr >= r) {
        return tree[idx];
    }

    int mid = l + (r-l)/2;
    int left = query(2*idx+1, l, mid, ql, qr);
    int right = query(2*idx+2, mid+1, r, ql, qr);
    return left&right;
}

int main()
{
    int t;  cin>>t;
    
    while(t--) {
        // input starts here
        int n, k;   cin>>n>>k;
        vector<int>vec(n*3);

        for(int i = 0; i < n; i++) {
            int x;  cin>>x;
            vec[i] = x;     vec[n+i] = x;       vec[2*n+i] = x;
        }

        int idx = 0, l = 0, r = 3*n-1;
        int n_ele = 6*n - 1;
        int temp = ceil(log2(n_ele));
        int len = pow(2, temp) - 1;
        tree.resize(len);
        buildTree(vec, idx, l, r);

        for(int i = 0; i < n; i++) {
            int ql = max(n+i-k, 0);
            int qr = min(n+i+k, 3*n-1);
            cout<<query(idx, l, r, ql, qr)<<" ";
        } cout<<endl;
    }

    return 0;
}