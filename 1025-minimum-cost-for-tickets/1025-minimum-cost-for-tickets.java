import java.util.Arrays;
class Solution {
    public int solve(int[] days,int[] cost,int i,int[] dp){
        int n = days.length;
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int day = cost[0] + solve(days,cost,i+1,dp);
        int j;
        for( j=i;j<n && days[j]<days[i]+7;j++);

        int week = cost[1]+ solve(days,cost,j,dp);
        int k ;
        for(k = i;k<n && days[k]<days[i]+30;k++);
        int month = cost[2]+solve(days,cost,k,dp);
        // System.out.println("Days = "+day+"Week ="+week+"Months ="+month);
        dp[i] = Math.min(day,Math.min(week,month));
        return dp[i];
        
    }
    public int mincostTickets(int[] days, int[] costs) {
        int[] dp = new int[days.length+1];
        Arrays.fill(dp,-1);
        return solve(days,costs,0,dp);
    }
}