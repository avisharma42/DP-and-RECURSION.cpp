class Solution {
  public:
  int t[1001][1001];
   int solve(int W, vector<int> &val, vector<int> &wt, int n){
       if(n==0 || W==0) return t[n][W]=0;
       if(t[n][W]!=-1) return t[n][W];
       
       //choice daigram
       if(wt[n-1]<=W){
       t[n][W] =  max(solve(W,val,wt,n-1),val[n-1]+solve(W-wt[n-1],val,wt,n-1));
       }
       else{
       t[n][W] = solve(W,val,wt,n-1);
       }
       return t[n][W];
   }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
    memset(t,-1,sizeof(t));
   int n  = val.size();
 
   return solve(W,val,wt,n);
   
    }
};