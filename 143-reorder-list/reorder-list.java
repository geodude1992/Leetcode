/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {
        // find middle
        ListNode slow = head;
        ListNode fast = head.next;
        while((fast != null) && (fast.next != null)){
            slow = slow.next;
            fast = fast.next.next;
        }

        // reverse second half
        // sec, sec.nex, prev
        ListNode second = slow.next;    // slow = 3, sec=4
        ListNode prev = slow.next = null;   
        while(second != null){
            ListNode temp = second.next; //temp=5, temp=n
            second.next = prev; // secnex=null, senx=4
            prev = second;  // prev=4, prev=5
            second = temp;  // sec=5, sec=n
        }   // prev, sec.nex, sec

        // merge two halfs
        ListNode first = head;
        second = prev;
        while(second != null){
            ListNode temp1 = first.next;
            ListNode temp2 = second.next;
            first.next = second;
            second.next = temp1;
            first = temp1;
            second = temp2;
        }
    }
}