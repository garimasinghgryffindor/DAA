// TLE
// BRUTE FORCE APPROACH
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <set>
using namespace std;

struct node {
    int count;
    set<int>st;
    node() {}
    node(int x) {
        count = x;
    }
    node(int x, set<int>st_) {
        count = x;
        st = st_;
    }
};

vector<node> tree;
int n;
vector<int>vec;

node merge(node left, node right) {
    set<int> newst;
    newst.insert(left.st.begin(), left.st.end());
    newst.insert(right.st.begin(), right.st.end());
    int newCount = newst.size();
    node newNode = node(newCount, newst);

    return newNode;
}

void buildTree(int idx, int l, int r) {
    if(l > r) return;

    if(l == r) {
        set<int> temp;
        temp.insert(vec[l]);
        tree[idx] = node(1, temp); 
        return;
    }

    int mid = l + (r-l)/2;
    buildTree(2*idx+1, l, mid);
    buildTree(2*idx+2, mid+1, r);
    node newNode = merge(tree[2*idx+1], tree[2*idx+2]);
    tree[idx] = newNode;
}

node query(int idx, int l, int r, int&ql, int&qr) {
    // no overlap condition
    if(l > r || ql > r || qr < l) return 0;

    // complete overlap condition
    if(ql <= l && qr >= r) {
        return tree[idx];
    }

    // partial overlap condition
    int mid = l + (r-l)/2;
    node left = query(2*idx+1, l, mid, ql, qr);
    node right = query(2*idx+2, mid+1, r, ql, qr);
    return merge(left, right);
}


int main()
{
    // input starts here
    cin>>n;
    vec.resize(n);
    for(int i = 0; i < n; i++) {
        cin>>vec[i];
    }
    // input ends here

    int n_ele = 2*n-1;
    int temp = ceil(log2(n_ele));
    int len = pow(2, temp) - 1;
    tree.resize(len);

    // setting the arguements
    int idx = 0, l = 0, r = n-1;
    buildTree(idx, l, r);

    // input starts here
    int q;  cin>>q;
    for(int i = 0; i < q; i++) {
        int ql, qr;     cin>>ql>>qr;
        // input ends here

        int idx = 0, l = 0, r = n-1;
        ql--;
        qr--;
        auto ans = query(idx, l, r, ql, qr);
        cout<<ans.count<<endl;
    }

    return 0;
}
