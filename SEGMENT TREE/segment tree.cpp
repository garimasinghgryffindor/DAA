// User function Template for C++

class Solution{
public:
    void buildTree(vector<int>&tree, int arr[], int l, int r, int idx) {
        if(r < l) return;
        
        if(l == r) {
            tree[idx] = arr[l];     return;
        }
        
        int mid = l + (r-l)/2;
        
        // like Postorder traversal
        buildTree(tree, arr, l, mid, 2*idx+1);
        buildTree(tree, arr, mid+1, r, 2*idx+2);
        
        tree[idx] = tree[2*idx+1] + tree[2*idx+2];
    }
    
    int query(vector<int>tree, int idx, int l, int r, int ql, int qr) {
        
        
        if(ql > r || qr < l) {
            // no overlap
            return 0;
        }
        
        if(l >= ql && r <= qr) {
            // complete overlap
            return tree[idx];
        }
        
        // partial overlap
        int mid = l + (r-l)/2;
        int left = query(tree, 2*idx+1, l, mid, ql, qr);
        int right = query(tree, 2*idx+2, mid+1, r, ql, qr);
        
        return (left + right);
    }

    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        int num_of_elements = 2*n - 1;
        int temp = ceil(log2(num_of_elements));
        int segmentTreeLen = pow(2, temp) - 1;
        
        vector<int>segmentTree(segmentTreeLen, -1);
        
        int l = 0, r = n-1, idx = 0;
        buildTree(segmentTree, arr, l, r, idx);
        
        vector<int>res;
        
        for(int i = 0; i < 2*q; i+=2) {
            int ql = queries[i], qr = queries[i+1];
            int idx = 0, l = 0, r = n-1;
            int ans = query(segmentTree, idx, l, r, ql-1, qr-1);
            res.push_back(ans);
        }
        
        return res;
    }
};
