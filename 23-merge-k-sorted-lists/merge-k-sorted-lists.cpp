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
    // Brute Force T: O(N log N) | S: O(N)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nodes;
        ListNode head(0);           // Create actual node object. not pointer
        ListNode* point = &head;    // Create pointer to the node and reference head
        for(ListNode* l : lists){
            while(l){
                nodes.push_back(l->val);
                l = l->next;
            }
        }
        sort(nodes.begin(), nodes.end());
        for(int n : nodes){
            point->next = new ListNode(n);
            point = point->next;
        }
        return head.next;   // return head object not pointer i.e. head->next
    }

    /* PQ T: O(N log N) | S: O(N)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(0);           // Create actual node object. not pointer
        ListNode* point = &head;    // Create pointer to the node and reference head
        
        // Min Heap
        priority_queue<ListNode*, vector<ListNode*>, greater<int>> pq;
        for(auto l : lists){
            if(l) pq.push(l);
        }
        
        while(!pq.empty()){
            point->next = pq.top(); pq.pop();
            point = point->next;
            if(point->next) pq.push(point->next);
        }

        return head.next;   // return head object not pointer i.e. head->next
    }*/
};