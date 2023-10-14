void countingSort(int arr[], int place, int n) {
    int count[RANGE]={0,0,0,0,0,0,0,0,0,0};

    int output[n];

    for(int i=0 ; i<n ; i++) {
        count[(arr[i]/place)%10]++;
    }

    // cummulating
    for(int i=1 ; i<RANGE ; i++) {
        count[i] = count[i-1] + count[i];
    }

    for(int i=n-1 ; i>=0 ; i--) {
        int index = (arr[i]/place)%10;
        int pos = count[index]-1;
        output[pos] = arr[i];
        count[index]--;
    }

    for(int i=0 ; i<n ; i++) {
        arr[i] = output[i];
    }

}

void radixSort(int arr[], int n) {
    int max = getMax(arr,n);

    for(int i=1 ; max/i>0 ; i*=10) {
        countingSort(arr, i, n);
    }
}

