int knapSack(int W, int wt[], int val[], int n) 
{ 
   // using recursion
   // take or not take
   if(n <= 0) return 0;
   if(W == 0) return 0;
   // either you will take nth item 
   int res = 0;
   if(W-wt[n-1] >= 0) {
       res = max(res, val[n-1] + knapSack(W-wt[n-1], wt, val, n-1));
   }
   
   res = max(res, knapSack(W, wt, val, n-1));
   return res;
}


