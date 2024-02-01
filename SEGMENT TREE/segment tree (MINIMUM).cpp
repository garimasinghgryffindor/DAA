/* The functions which 
builds the segment tree */
void buildTree(int tree[], int arr[], int idx, int l, int r) {
    if(l > r) return;
    
    if(l == r) {
        tree[idx] = arr[l];     return;
    }
    
    int mid = l + (r-l)/2;
    buildTree(tree, arr, 2*idx+1, l, mid);
    buildTree(tree, arr, 2*idx+2, mid+1, r);
    
    tree[idx] = min(tree[2*idx+1], tree[2*idx+2]);
}

int *constructST(int arr[],int n)
{
    int num_elements = 2*n - 1;
    int temp = ceil(log2(num_elements));
    int len = pow(2, temp) - 1;
    
    int* tree = (int *)malloc(len * sizeof(int));
    memset(tree, INT_MAX, sizeof(tree));
    int idx = 0, l = 0, r = n-1;
    
    buildTree(tree, arr, idx, l , r);
    
    return tree;
}


/* The functions returns the
 min element in the range
 from a and b */
 
 int query(int tree[], int ql, int qr, int idx, int l, int r) {
     if(ql > r || qr < l) return INT_MAX;
     
     if(l >= ql && r <= qr) {
         return tree[idx];
     }
     
     int mid = l + (r-l)/2;
     
     int left = query(tree, ql, qr, 2*idx+1, l, mid);
     int right = query(tree, ql, qr, 2*idx+2, mid+1, r);
     return min(left, right);
 }
 
int RMQ(int st[] , int n, int a, int b)
{
    // int * tree = constructST(st, n);
    
    int idx = 0;
    int l = 0, r = n-1;
    return query(st, a, b, idx, l, r);
}

