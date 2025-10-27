class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer,Integer> m = new HashMap<>();
        for(int i:nums){
            if(m.containsKey(i)){
                m.put(i,m.get(i)+1);
            }
            else{
                m.put(i,1);
            }
        }
        for(int i:m.values()){
            if(i>=2){
                return true;

            }
        }
        return false;
        
    }
}