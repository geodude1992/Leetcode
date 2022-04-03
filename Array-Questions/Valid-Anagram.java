class Solution {
    public static String sortString(String inputString){
        // Converting input string to character array
        char tempArray[] = inputString.toCharArray();
        // Sorting temp array using
        Arrays.sort(tempArray);
        // Returning new sorted string
        return new String(tempArray);
    }
 
    public boolean isAnagram(String s, String t) {
        String a = sortString(s);
        String b = sortString(t);
        if(a.equals(b)){
            return true;
        }
        return false;
    }
    
}
