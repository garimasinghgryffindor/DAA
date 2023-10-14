// RANDOMIZED QUICK SORT
int partition(vector<int>&arr, int l, int r) {
    int rnd = rand()%(r-l) + l;
    swap(arr[rnd], arr[r]);
    
    int pivot = arr[r];
    int k = l-1;
    
    for(int j = l; j < r; j++) {
        if(arr[j] < pivot) {
            k++;
            swap(arr[k], arr[j]);
        }
    }
    swap(arr[k+1], arr[r]);
    
    return k+1;
}

void quickSort(vector<int>&arr, int l, int r) {
    if(l < r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);
    }
}

vector<int> sortArray(vector<int>& nums) { 
    // Divide and Conquer algo
    // picks an element as a pivot and partitions the given array around the picked pivot
    // The target of partitions is to place the pivot at its correct position in the sorted array 
    // and put all smaller elements to the left of the pivot, 
    // and all greater elements to the right of the pivot.
    int n = nums.size();
    vector<int> res(nums.begin(), nums.end());
    
    quickSort(res, 0, n-1);
    
    return res;
}
