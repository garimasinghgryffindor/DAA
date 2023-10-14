// MERGE SORT
void merge(vector<int>&arr, int l, int mid, int r) {
    int n1 = mid-l+1;
    int n2 = r-mid;
    vector<int>left(n1), right(n2);
    for(int i = 0; i < n1; i++) {
        left[i] = arr[i+l];
    }
    for(int i = 0; i < n2; i++) {
        right[i] = arr[mid+1+i];
    }
    
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    
    while(i < n1) {
        arr[k++] = left[i++];
    }
    while(j < n2) {
        arr[k++] = right[j++];
    }
}

void mergeSort(vector<int>&arr, int l, int r) {
    if(l < r) {
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

vector<int> sortArray(vector<int>& nums) { 
    // Divide and Conquer algo
    // dividing an array into smaller subarrays, 
    // sorting each subarray, 
    // and then merging the sorted subarrays back together to form the final sorted array.
    int n = nums.size();
    vector<int> res(nums.begin(), nums.end());
    
    mergeSort(res, 0, n-1);
    
    return res;
}


