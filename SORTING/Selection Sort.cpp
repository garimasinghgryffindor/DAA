// SELECTION SORT
vector<int> sortArray(vector<int>& nums) {
    // repeatedly selecting the smallest (or largest) element from the unsorted portion 
    // of the list and moving it to the sorted portion of the list. 
    int n = nums.size();
    vector<int> res(nums.begin(), nums.end());
    
    for(int i = 0; i < n; i++) {
        int mn = i;
        for(int j = i+1; j < n; j++) {
            if(res[j] < res[mn]) {
                mn = j;
            }
        }
        if(mn != i) {
            swap(res[i], res[mn]);
        }
    }
    
    return res;
}
