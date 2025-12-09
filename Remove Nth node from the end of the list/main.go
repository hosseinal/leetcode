/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func lenList(head *ListNode) int{
    counter := 0
    for head != nil {
        counter++
        head = head.Next
    }
    return counter
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {

    s :=lenList(head)
    step := s - n

    if step == 0 {
        return head.Next
    }

    prev := head
    start := head
    
    for i := 0 ; i < step; i++ {
        prev = start
        start = start.Next
    }

    prev.Next = start.Next

    return head
    
}

