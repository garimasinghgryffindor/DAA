// INSERTION SORT
vector<int> sortArray(vector<int>& nums) {
    // The array is virtually split into a sorted and an unsorted part. 
    // Values from the unsorted part are picked and placed at the correct 
    // position in the sorted part.
    // similar to the way you sort playing cards in your hands. 
    int n = nums.size();
    vector<int> res(nums.begin(), nums.end());
    
    for(int i = 1; i < n; i++) {
        int key = res[i];
        int j = i-1;
        while(j >= 0 && res[j] > key) {
            // shift
            res[j+1] = res[j];
            j--;
        }
        res[j+1] = key;
    }
    
    return res;
}

