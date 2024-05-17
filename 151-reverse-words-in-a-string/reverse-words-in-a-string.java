class Solution {
    public String reverseWords(String s) {
        // trim() to remove leading and trailing spaces
        String[] arr = s.trim().split("\\s+");

        // initialize the output string
        StringBuilder output = new StringBuilder();
        
        // iterate through the words in reverse
        for(int i = arr.length - 1; i >= 0; i--){
            // append the current word and a space to the output
            output.append(arr[i]).append(" ");
        }

        return output.toString().trim();
    }
}