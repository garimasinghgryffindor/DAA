// using RECURSION
    int recur(int arr[], int i, int j) {
        if(i == j) return 0;
        
        int mn = INT_MAX;
        for(int k = i; k < j; k++) {
            int temp = arr[i-1]*arr[k]*arr[j];
            mn = min(mn, temp + recur(arr,i,k) + recur(arr, k+1, j));
        }
        
        return mn;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        return recur(arr, 1, N-1);
    }
