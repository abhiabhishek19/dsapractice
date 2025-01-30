/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *ans = (int *)malloc((digitsSize + 1) * sizeof(int));
    *returnSize = digitsSize;
    int i;
    int sum = 1; /* plus one */
    for (i = digitsSize - 1; i >= 0; i--) {
        sum += digits[i];
        ans[i + 1] = sum % 10;
        sum /= 10;
    }
    if (sum) {
        ans[0] = sum;
        *returnSize = *returnSize + 1;
        return ans;
    }
    else {
        return ans + 1;
    }
}