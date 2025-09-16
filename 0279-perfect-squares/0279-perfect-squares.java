class Solution {
    public int solve(int n){
        int[] dp = new  int[n+1];
        dp[0] = 0;
        for(int j = 1;j<=n;j++){
            dp[j]=n;
             for(int i=1;i*i<=n;i++){
                if(j-(i*i)>=0){
                    dp[j] = Math.min(dp[j],1+ dp[j-(i*i)]);
                }
                
            }
        }
       
        return dp[n];
        
    }
    public int numSquares(int n) {
        return solve(n);
    }
}