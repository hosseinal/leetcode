/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {

    var start *ListNode
    var prev *ListNode

    if list1 == nil {
        return list2
    }

    if list2 == nil {
        return list1
    }
    
    if list1.Val < list2.Val {

        start = list1
        prev = list1
        list1 = list1.Next

    } else {

        start = list2
        prev = list2
        list2 = list2.Next

    }
    
    for list1 != nil && list2 != nil {
        var val1 = 101
        if list1 != nil {
            val1 = list1.Val
        }

        var val2 = 101
        if list2 != nil {
            val2 = list2.Val
        }

        if val1 < val2 {
           prev.Next = list1
           prev = prev.Next
           list1 = list1.Next
        }else{
            prev.Next = list2
            prev = prev.Next
            list2 = list2.Next
        }

        
    }
    // prev.Next = nil

    // Attach the remaining list (if any)
    if list1 != nil {
        prev.Next = list1
    } else if list2 != nil {
        prev.Next = list2
    }

    return start
}

