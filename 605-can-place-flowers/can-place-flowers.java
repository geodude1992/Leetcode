class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int spaces = 0;

        for(int i = 0; i < flowerbed.length; i++){
            // Check if current space is empty
            if(flowerbed[i] == 0){
                // check if its neighboring spaces are also empty or are at the ends of the arr
                boolean isLeftEmpty = i == 0 || flowerbed[i-1] == 0;
                boolean isRightEmpty = i == flowerbed.length - 1 || flowerbed[i+1] == 0;

                // if both are empty we can plant a flower
                if(isLeftEmpty && isRightEmpty){
                    flowerbed[i] = 1;
                    spaces++;

                    // optimized
                    if(spaces >= n) return true;
                }
            }
        }
        return spaces >= n;
    }
}