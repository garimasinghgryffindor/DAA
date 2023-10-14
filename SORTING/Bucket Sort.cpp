void bucketSort(vector<double>&arr, int n) {
    vector<double> buckets[n];

    // sorting the array elements into buckets
    for(int i=0 ; i<arr.size() ; i++) {
        int index = arr[i]*n;
        buckets[index].push_back(arr[i]);
    }

    // sorting the elements within individual buckets
    for(int i=0 ; i<n ; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<buckets[i].size() ; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// input 0.897 0.565 0.656 0.1234 0.665 0.3434 
