class Solution {
    public String reverseVowels(String s) {
        char[] sArr = s.toCharArray();
        int l = 0;
        int r = sArr.length - 1;

        //String vowels = "aeiouAEIOU";
        Set<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));

        while(l < r){
            // Move left ptr til it points to a vowel
            while(l < r && !vowels.contains(sArr[l])){
                l++;
            }
            while(l < r && !vowels.contains(sArr[r])){
                r--;
            }

            // swap vowels
            char temp = sArr[l];
            sArr[l] = sArr[r];
            sArr[r] = temp;

            // move ptrs
            l++;
            r--;
        }
        String ans = new String(sArr);
        return ans;
    }
}