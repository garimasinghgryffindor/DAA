#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

struct node {
    int max1, max2, sum;
	node() {}
	node(int val) {
		max1 = val;
        max2 = INT_MIN;
        sum = val;
	}
    node(int v1, int v2, int sum_) {
        max1 = v1;
        max2 = v2;
        sum = sum_;
    }
};

#define vi vector<int>
#define vn vector<node>

vector<node> tree;

node merge(node left, node right) {
    int newMax1, newMax2;
    if(left.max1 >= right.max1) {
        newMax1 = left.max1;
        if(right.max1 >= left.max2) {
            newMax2 = right.max1;
        } else {
            newMax2 = left.max2;
        }
    } else {
        newMax1 = right.max1;
        if(right.max2 >= left.max1) {
            newMax2 = right.max2;
        } else {
            newMax2 = left.max1;
        }
    }

    node ret = node(newMax1, newMax2, newMax1+newMax2);
    return ret;
}

void buildTree(vi&vec, int idx, int l, int r) {
    if(l > r) return ;

    if(l == r) {
        tree[idx] = node(vec[l]);   return;
    }

    int mid = l + (r-l)/2;
    buildTree(vec, 2*idx+1, l, mid);
    buildTree(vec, 2*idx+2, mid+1, r);
    tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
}

node query(int idx, int ql, int qr, int l, int r) {
    // no overlap
    if(r < ql || l > qr) {
        return node(INT_MIN);
    }

    // complete overlap
    if(l >= ql && qr >= r) {
        return tree[idx];
    }

    // partial overlap
    int mid = l + (r-l)/2;
    node left = query(2*idx+1, ql, qr, l, mid);
    node right = query(2*idx+2, ql, qr, mid+1, r);
    return merge(left, right);
}

void update(int&pos, int&val, int idx, int l, int r) {
    // no overlap
    if(pos < l || pos > r) return;

    // complete overlap
    if(pos == l && l == r) {
        tree[idx] = node(val);  return;
    }

    // partial overlap
    int mid = l + (r-l)/2;
    if(mid >= pos) update(pos, val, 2*idx+1, l, mid);
    else update(pos, val, 2*idx+2, mid+1, r);

    tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
}


int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        cin>>vec[i];
    }

    int num_ele = 2*n-1;
    int temp = ceil(log2(num_ele));
    int len = pow(2, temp) - 1;
    //vector<node> tree(len, -1);
    tree.resize(len);

    int idx = 0, l = 0, r = n-1;
    buildTree(vec, idx, l, r);

    int q;  cin>>q;
    vector<int>res;
    for(int i = 0; i < q; i++) {
        char typ;   cin>>typ;
        int x, y;
        cin>>x>>y;
        if(typ == 'Q') {
            // query operation
            int ql = x-1, qr = y-1, idx = 0;
            int l = 0, r = n-1;
            node ans = query(idx, ql, qr, l, r);
            res.push_back(ans.sum);
        } else {
            // updation
            int pos = x-1, val = y;
            int idx = 0, l = 0, r = n-1;
            update(pos, val, idx, l, r);
        }
    }

    for(int i: res) {
        cout<<i<<endl;
    }

    return 0;
}