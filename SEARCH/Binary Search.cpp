class Solution {
public:
    // ITERATIVE BINARY SEARCH
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) 
                return mid;
            else if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return -1;
    }
};


class Solution {
public:
    // RECURSIVE BINARY SEARCH
    int binarySearch(vector<int>&nums,int l,int r,int&target) {
        if(l > r) return -1;
        
        int mid = l + (r-l)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target) return binarySearch(nums,mid+1,r,target);
        return binarySearch(nums,l,mid-1,target);
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        return binarySearch(nums, l , r, target);
    }
};


class Solution {
public:
    // BINARY JUMP SEARCH
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int k = 0;
        for(int i = n/2; i >= 1; i/=2) {
            while(k+i < n && nums[k+i] <= target) {
                k += i;
            }
        }
        
        if(k < n && nums[k] == target)
            return k;
        return -1;
    }
};


class Solution {
public:
    // BINARY EXPONENTIAL SEARCH
    int binarySearch(vector<int>&nums,int l, int r,int&target) {
        if(l > r) return -1;
        int mid = l + (r-l)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target) return binarySearch(nums, mid+1, r, target);
        return binarySearch(nums, l,mid-1,target);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int i = 1;
        while(i < n && nums[i] <= target) {
            i *= 2;
        }
        
        return binarySearch(nums, i/2, min(i,n-1), target);
    }
};
