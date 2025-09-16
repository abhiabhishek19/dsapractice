class Solution {
    public int solve(int[] num, int tar){
        int[] dp = new int[tar+1];
        dp[0] = 1;
        for(int i=1; i <=tar; i++){
            for(int j=0;j<num.length; j++){
                if(i-num[j]>=0){
                    dp[i] += dp[i - num[j]];
                }
                 
            }
        }
        return dp[tar];
    }
    public int combinationSum4(int[] nums, int target) {
        return solve(nums,target);
    }
}