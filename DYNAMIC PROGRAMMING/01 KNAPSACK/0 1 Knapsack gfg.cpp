// RECURSION
int recur(int W, int wt[], int val[], int i) {
     // take or not take
    if(i < 0) return 0;
    if(W <= 0) return 0;
    // either you will take nth item 
    int res = 0;
    if(W-wt[i] >= 0) {
        res = max(res, val[i] + recur(W-wt[i], wt, val, i-1));
    }

     // or not
    res = max(res, recur(W, wt, val, i-1));
    return res;
 }
 
 int knapSack(int W, int wt[], int val[], int n) 
 { 
    // using recursion
    return recur(W, wt, val, n-1);
 }


// MEMOIZATION
int recur(vector<vector<int>>&mem,int W, int wt[], int val[], int i) {
   // take or not take
   if(mem[i+1][W] != -1) return mem[i+1][W];
   
  if(i < 0) { return mem[i+1][W] = 0; }
  if(W <= 0) { return mem[i+1][W] = 0; }
  
  // either you will take nth item 
  int res = 0;
  if(W-wt[i] >= 0) {
      res = max(res, val[i] + recur(mem, W-wt[i], wt, val, i-1));
  }
  
  // or not
  res = max(res, recur(mem, W, wt, val, i-1));
  return { mem[i+1][W] = res };
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
  // using memoization
  vector<vector<int>> mem(n+1, vector<int>(W+1,-1));
  return recur(mem,W, wt, val, n-1);
}





