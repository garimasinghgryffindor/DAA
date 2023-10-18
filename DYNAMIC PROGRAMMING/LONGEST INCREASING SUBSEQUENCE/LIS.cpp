class Solution {
public:
    // using dp 
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis(nums.size(), 0 );
        lis[0] = 1;
        
        for(int i=1 ; i<nums.size() ; i++) {
            lis[i] = 1;
            for(int j=0 ; j<i ; j++) {
                if(nums[i] > nums[j] && lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                }
            }
        }
        
        return *max_element(lis.begin(), lis.end());
    }
};


// using RECURSION
int recur(int a[], int i, int n, int prev) {
    if(i == n) return 0;
    
    int res = 0;
    // either i will take it
    if(a[i] > prev) {
        res = 1 + recur(a, i+1, n, a[i]);
    }
    
    res = max(res, recur(a, i+1, n, prev));

    return res;
}

int longestSubsequence(int n, int a[])
{
    return recur(a, 0, n , -1);
}
