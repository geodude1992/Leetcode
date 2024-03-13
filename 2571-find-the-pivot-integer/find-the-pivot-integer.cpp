/*
int pivotInteger(int n) {
    // T: O(n^2)    S: O(1)
    // Brute Force check every number between 1 -> n for pivot i
    // 1st loop sum 1 -> i 
    // 2nd loop sum i -> n
    
    // Iterate through possible pivot values
    for(int i = 1; i <= n; i++){
        int sumLeft = 0;
        int sumRight = 0;

        // calculate the sum of elements on the left side of the pivot
        for(int j = 1; j <= i; j++){
            sumLeft += j;
        }

        // calculate the sum of elements on the right side of the pivot
        for(int k = i; k <= n; k++){
            sumRight += k;
        }

        // Check if the sums on both sides are equal
        if(sumLeft == sumRight){
            return i;   // Return pivot if found
        }
    }
    return -1;
}
*/
class Solution {
public:
    int pivotInteger(int n) {
        // T: O(1)      S: O(1)
        // Math Solution
        // [1 + 2+ ... + x = x + ... + n]
        // Arithmetic Progression   [(x(x+1))/2 = ((x+n)(n-x+1))/2]
        // Expand both sides        [x + x^2/2 = (nx - x^2 + x + n^2 - nx + n)]
        // Simplify and solve for x [2x^2 = n^2 + n]    
        // [x = sq((n^2 + n) / 2)]
        const int sum = (n * (n + 1) / 2);
        const int pivot = sqrt(sum);
        // if pivot * pivot is equal to sum return
        if(pivot * pivot == sum){
            return pivot;
        }else{
            return -1;
        }
    }
};