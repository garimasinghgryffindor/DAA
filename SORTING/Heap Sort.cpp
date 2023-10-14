// HEAP SORT
void heapify(vector<int>&res, int i, int n) {
    int c1 = 2*i + 1;
    int c2 = 2*i + 2;
    int max = i;
    if(c1 < n && res[max] < res[c1]) {
        max = c1;
    }
    if(c2 < n && res[max] < res[c2]) {
        max = c2;
    }
    
    if(max != i) {
        swap(res[i], res[max]);
        heapify(res, max, n);
    }
}

void buildHeap(vector<int>&res) {
    int n = res.size();
    for(int i = n/2; i >= 0; i--) {
        heapify(res, i, n);
    }
}

void heapSort(vector<int>&res) {
    int n = res.size();
    for(int i = 0; i < res.size(); i++) {
        swap(res[0], res[n-1]);
        n--;
        heapify(res, 0, n);
    }
}

vector<int> sortArray(vector<int>& nums) { 
    int n = nums.size();
    vector<int> res(nums.begin(), nums.end());
    
    buildHeap(res);
     
    heapSort(res);
    
    return res;
}


