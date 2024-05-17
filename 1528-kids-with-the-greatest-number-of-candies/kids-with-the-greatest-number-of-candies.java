class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        // find kid with the most candies

        // compare each kid + extra to see if its >= kid with max candies
        int maxCandies = 0;

        for(int c : candies){
            maxCandies = Math.max(c, maxCandies);
        }

        ArrayList<Boolean> answer = new ArrayList<>();

        for(int c : candies){
            answer.add(c + extraCandies >= maxCandies);
        }
        return answer;
    }
}