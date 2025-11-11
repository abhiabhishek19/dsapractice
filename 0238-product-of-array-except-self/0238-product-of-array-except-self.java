class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] pp = new int[nums.length];
        int[] sp = new int[nums.length];
        int fpp = 1;
        pp[0] = 0;
        int fsp = 1;
        sp[nums.length-1] = 0;
        for(int i =1;i<nums.length;i++){
            fpp = fpp*nums[i-1];
            pp[i] = fpp;
        }
        for(int i=nums.length-2;i>=0;i--){
            fsp = fsp*nums[i+1];
            sp[i] = fsp;
        }
        int[] ans = new int[nums.length];
        ans[0] = sp[0];
        ans[nums.length-1] = pp[nums.length-1];
        for(int i =1;i<nums.length-1;i++){
            ans[i] = pp[i]*sp[i];
        }
        return ans;

    }
}

