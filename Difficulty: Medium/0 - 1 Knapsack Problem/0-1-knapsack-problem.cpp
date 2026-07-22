class Solution {
  public:
  int t[1001][1001];
  
    int solve(int W,int n, vector<int>& val,vector<int>& wt){
      if(n==0 || W==0){
          return 0;
      }
      if(t[n][W]!=-1){
          return t[n][W];
      }
      if(W>=wt[n-1]){
          t[n][W] = max(val[n-1]+solve(W-wt[n-1],n-1,val,wt),solve(W,n-1,val,wt));
      }
      else{
          return t[n][W] = solve(W,n-1,val,wt);
      }
      return t[n][W];
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
      
        memset(t,-1,sizeof(t));
        int n = val.size();
     int ans = solve(W,n,val,wt);
     return ans;
    }
};