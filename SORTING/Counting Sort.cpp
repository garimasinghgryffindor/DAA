// COUNTING SORT
vector<int> sortArray(vector<int>& nums) { 
    int n = nums.size();
    vector<int> res(nums.begin(), nums.end());
    map<int,int>mp;
    for(int x: res) {
        mp[x]++;
    }
    
    int k = 0;
    for(auto x: mp) {
        int num = x.first, freq = x.second;
        for(int j = 0; j < freq; j++) {
            res[k++] = num;
        }
    }
    
    return res;
}
