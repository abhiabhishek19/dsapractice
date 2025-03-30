#define MOD 1000000007

int waysToReachTarget(int target, int** types, int typesSize, int* typesColSize) {
    // DP array where dp[j] stores the number of ways to get exactly j points
    int *dp = (int*)calloc(target + 1, sizeof(int));
    dp[0] = 1;  // Base case: one way to get 0 points (by solving no questions)

    // Iterate through each type of question
    for (int i = 0; i < typesSize; i++) {
        int count = types[i][0];  // Maximum count of this type of question
        int marks = types[i][1];  // Marks per question

        // Update DP array from right to left to avoid recomputation issues
        for (int j = target; j >= 0; j--) {
            long long sum = 0;
            for (int k = 1; k <= count && j - k * marks >= 0; k++) {
                sum = (sum + dp[j - k * marks]) % MOD;
            }
            dp[j] = (dp[j] + sum) % MOD;
        }
    }

    int result = dp[target];
    free(dp);
    return result;
}