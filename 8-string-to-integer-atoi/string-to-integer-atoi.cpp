class Solution {
public:
    int myAtoi(string s) {
        // Initialize variables i (for iterating through the string), sign (to store the sign of the number), and number (to accumulate the converted integer).
        long int num = 0;
        int i = 0;
        int sign = 1;
        
        // Skip leading 0's
        while(i < s.length() && s[i] == ' ') i++;

        // Determine the sign
        if(s[i]=='-'){
            sign = -1; 
            i++;
        }
        else if(s[i] == '+') i++;

        // Traverse the remaining chars and convert to int
        while(i < s.length()){        
            if(s[i] >= '0' && s[i]<='9'){
                num = num * 10 + (s[i]-'0');
                if(num > INT_MAX && sign == -1)
                    return INT_MIN;
                else if(num > INT_MAX && sign == 1) 
                    return INT_MAX;
                i++;
            } else return num * sign;        
        }
        return num * sign;
    }
};