class Solution {
public:
    bool isValid(string s) {
        // stack for keeping track of order of brackets, holds ONLY opening sym, stack has top() which vector doesnt
        stack<char> stk;
        // iterate through string
        for(auto sym : s){
            // if current sym is an opening push to stack
            if(sym == '(' || sym == '{' || sym == '[') stk.push(sym);
            // if current sym is a closing we pop from stack if its opposing match
            // return false if the stack is empty or the top of stack is not the opposing matching symbol
            else{
                if (stk.empty() || (stk.top() == '(' && sym != ')') || 
                    (stk.top() == '{' && sym != '}') || 
                    (stk.top() == '[' && sym != ']'))
                return false; 
                stk.pop();
            }
        }
        // theres a chance we have an opening sym left in that stack
        return stk.empty();
    }
};