/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    string gameResult(ListNode* head) {
        // string is 'Even' if sp is positive, 0 is tie, and negative is 'Odd' 
        int sp = 0;
        ListNode* evenNode = head;
    
        while(evenNode!=nullptr){
            ListNode* oddNode = evenNode->next;
            if(oddNode->val == evenNode->val){
                continue;
            }else if(oddNode->val > evenNode->val) {
                sp--;;
            }else{
                sp++;;
            }
            evenNode = oddNode->next;
        }
        std::string result = (sp < 0) ? "Odd" : 
                             (sp == 0) ? "Tie" : "Even";
    
        return result;
    }
};