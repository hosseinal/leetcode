/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// method 1
func hasCycle(head *ListNode) bool {
    if head == nil {
        return false
    }

    m := make(map[*ListNode]bool)
    condition := true

    for condition {
        _, found := m[head]
        
        if found {
            return true
        }else{
            m[head] = true
           
        }

        if head.Next == nil {
            condition = false
        }
        head = head.Next
    }

    return false
    
}


// method 2
func hasCycle(head *ListNode) bool {
    if head == nil {
        return false
    }

    m := make(map[*ListNode]bool)
    condition := true

    for condition {
        _, found := m[head]
        
        if found {
            return true
        }else{
            m[head] = true
           
        }

        if head.Next == nil {
            condition = false
        }
        head = head.Next
    }

    return false
    
}

// method 2
func hasCycle(head *ListNode) bool {
    if head == nil {
        return false
    }

   slow := head
   fase := head

   if fast != nil && fast.Next != nil {
    slow = slow.next
    fast = fast.Next.Next
    if slow == fast {
        return true
     }
   }

   return false
    
}

