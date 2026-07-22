class Solution {
  public:
  
  
    int solve(int W,int n, vector<int>& val,vector<int>& wt){
        //initializatrion
        int t[n+1][W+1];
        for(int i = 0; i<=n ; i++){
            for(int j  = 0 ; j<=W ; j++){
                if(i==0||j==0){
                    t[i][j] = 0;
                }
            }
        }
        
        //recusrsive calls to the iterations
        for(int i = 1; i<=n ; i++){
            for(int j = 1 ; j<=W ; j++){
                if(wt[i-1]<=j){
                    t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]] , t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
            
        }
        return t[n][W];
     
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        return solve(W,n,val,wt);
      
    }
};