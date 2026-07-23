class Solution {
  public:
  int solve(vector<int>& arr, int target,int n){
      vector<vector<int>> t(n+1,vector<int>(target+1));
      //base case
      for(int i = 0; i<= n ;i++){
          for(int j = 0; j<=target ; j++){
              if(i==0 && j==0) t[i][j] = 1;
              if(i==0) t[i][j] =0;
              if(j==0) t[i][j]=1;
          }
      }
       for(int i = 1; i<= n ;i++){
          for(int j = 0 ; j<=target ; j++){
              if(arr[i-1]==0) t[i][j] = t[i-1][j]*2;
              if(arr[i-1]<=j) t[i][j] =t[i-1][j-arr[i-1]]+t[i-1][j];
              else t[i][j] = t[i-1][j];
          }
      }
      return t[n][target];
  }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        return solve(arr,target,n);
    }
};