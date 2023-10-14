// COUNTING SORT
vector<int> sortArray(vector<int>& nums) { 
    int n = nums.size();
    vector<int> res(nums.begin(), nums.end());
    int max_ = *max_element(res.begin(), res.end());
    int min_ = *min_element(res.begin(), res.end());
    
    int n2 = max_ - min_ + 1;
    vector<int>count(n2, 0);
    for(int x: res) {
        int num = x - min_;
        count[num]++;
    }
    
    for(int i = 1; i < n2; i++) {
        count[i] = count[i-1] + count[i];
    }
    
    for(int i = n-1; i >= 0; i--) {
        int posi = count[nums[i]-min_] - 1;
        res[posi] = nums[i];
        count[nums[i]-min_]--;
    }
    
    return res;
}
