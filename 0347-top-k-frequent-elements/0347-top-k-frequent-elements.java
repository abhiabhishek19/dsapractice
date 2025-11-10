class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> m = new HashMap<>();
        for(int i:nums){
            if(m.containsKey((Integer)i)){
                int v = m.get(i);
                m.put(i,++v);
            }
            else {
                m.put(i,1);
            }
        }
        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(m.entrySet());
        list.sort((a, b) -> b.getValue().compareTo(a.getValue()));

        // Step 3: Take the top k elements
        int[] ans = new int[k];
        for (int i = 0; i < k; i++) {
            ans[i] = list.get(i).getKey();   // ✅ fixed: get key, not value list indexing
        }

        return ans;
    }
}