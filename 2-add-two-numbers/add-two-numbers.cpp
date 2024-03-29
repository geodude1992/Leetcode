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
    /*
    EXPLANATION
        1. WE have to Traverse Both Lists & add sum to new list.
        2. Sum is equivalent to val1 + val2 + carry from previous Operation.
        3. THe resulting node will be sum%10.
        4. Carry is updated by sum/10 for next Opeartion.
        
        Time Complexity O(n).
        Space Compelxity O(max(l1,l2)).
    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr = new ListNode();     //new list;
        ListNode *temp = ptr;
        
        int carry = 0;
		//traversing both list till one of the list not reaches NULL
        while (l1 != nullptr ||  l2 != nullptr || carry)
        {
            int sum = 0;
			// if l1  is not null
			// add l1-> value to sum
            if(l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1 -> next;
            }
            
			// if l2  is not null
			// add l2-> value to sum
            if(l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2 -> next;
            }
            
			// add carry to sum
            sum += carry;
			// carry is updated by sum/10 because for 18 , 
			// 18 / 10 is 1 which is the carry
            carry = sum/10;

			// add sum% 10 to new node as it containg the sum
            ListNode *node = new ListNode(sum % 10);
            temp -> next = node;
            temp = temp -> next;
        }
        ListNode* result = ptr -> next;
        delete ptr; // Freeing the memory allocated for dummyHead
        return result;
    }
};