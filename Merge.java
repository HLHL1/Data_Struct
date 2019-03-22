/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode Merge(ListNode list1,ListNode list2) {
        ListNode l=null,list=null;
        ListNode l1=list1,l2=list2;
        if(list1==null){
            return list2;
        }
        if(list2==null){
            return list1;
        }
        if(l1.val>=l2.val){
            list=l2;
            l2=l2.next;
        }else{
            list=l1;
            l1=l1.next;
        }
        l=list;
        while(l1!=null&&l2!=null){
            if(l1.val>=l2.val){
                list.next=l2;
                list=list.next;
                l2=l2.next;
            }else {
                list.next=l1;
                 list=list.next;
                l1=l1.next;
            }
        }
        while(l1!=null){
            list.next=l1;
             list=list.next;
            l1=l1.next;
        }
        while(l2!=null){
            list.next=l2;
             list=list.next;
            l2=l2.next;
        }
        return l;
    }
}