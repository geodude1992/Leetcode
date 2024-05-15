class Solution {
    public String longestCommonPrefix(String[] strs) {
        // Initialize an empty string ans to store the common prefix.
        StringBuilder answer = new StringBuilder();

        // Sort the input list v lexicographically. 
        // This step is necessary because the common prefix should be common to all the strings, so we need to find the common prefix of the first and last string in the sorted list.
        Arrays.sort(strs);

        // Iterate through the characters of the first and last string in the sorted list, stopping at the length of the shorter string.
        String first = strs[0];
        String last = strs[strs.length-1];
        for(int i =-0; i < Math.min(first.length(), last.length()); i++){
            // If the current character of the first string is not equal to the current character of the last string, return the common prefix found so far.
            if(first.charAt(i) != last.charAt(i)) 
                return answer.toString();

            // Otherwise, append the current character to the ans string.
            answer.append(first.charAt(i));
        }
        // Return the ans string containing the longest common prefix.
        return answer.toString();
    }
}