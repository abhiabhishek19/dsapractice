class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()){
            return false;
        }
        else {
            HashMap<Character,Integer> m = new HashMap<>();
       for(int i=0;i< s.length();i++){
        Integer c = m.get(s.charAt(i));
        if(!(c == null)){
            m.put(s.charAt(i),++c);
        }
        else {
            m.put(s.charAt(i),1);
        }
        

       }
       for(int j=0;j<t.length();j++){
        Integer d = m.get(t.charAt(j));
        if(m.containsKey(t.charAt(j)) && d>0){
            m.put(t.charAt(j),--d);
        }
        else {
            return false;
        }
       }
       return true;
        }
       

    }
}