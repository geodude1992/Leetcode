/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
        // Store nodes from LLB to a hashset
        HashSet<ListNode> nodesInB = new HashSet<ListNode>();
        while(headB != null){
            nodesInB.Add(headB);
            headB = headB.next;
        }
        // Check if a node in LLB is in LLA
        while(headA != null){
            if(nodesInB.Contains(headA)){
                return headA;
            }
            headA = headA.next;
        }
        return null;
    }
}