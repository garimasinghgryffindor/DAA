// BUBBLE SORT
vector<int> sortArray(vector<int>& nums) {
    // swapping for wrong order
    int n = nums.size();
    vector<int> res(nums.begin(), nums.end());
    
    for(int i = 0; i < n; i++) {
        for(int j = ; j < n-i; j++) {
            if(res[j] < res[j-1]) {
                swap(res[j], res[j-1]);
            }
        }
    }
    
    return res;
}

