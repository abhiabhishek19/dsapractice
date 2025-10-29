class Solution {
    public int Search(int []nums,int target,int i){
        
        int ans =-1;
        for(int j=0;j<nums.length;j++){
            if(nums[j]==target){
                ans=j;
            }
        }
        if(ans!=i){
            return ans;
        }
        return -1;
        
    }
    public int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        
        for(int i=0;i<nums.length;i++){
            int n = nums[i];
            int pos=Search(nums,target-n,i);
            
            if(pos>=0){
                ans[0] = i;
                ans[1] = pos;
                return ans;
            }
        }
        return ans;
    }
}