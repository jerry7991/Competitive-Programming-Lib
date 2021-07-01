
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class ReverseLinkedListII {
   public

      ListNode reverseBetween(ListNode head, int left, int right) {
        if(head == null || left == right) return head;

        ListNode curr=head,prev=null;
        while(left>1){
            prev=curr;
            curr=curr.next;
            left--;
            right--;
        }

        ListNode con = prev, tail = curr, third = null;
        while(right>0){
            third = curr.next;
            curr.next = prev;
            prev = curr;
            curr= third;
            right--;
        }

        if(con!=null){
            con.next=prev;
        }else{
            head = prev;
        }
        tail.next  = curr;
        return head;
    }

    public static void main(String[] args) {
        
    }
}