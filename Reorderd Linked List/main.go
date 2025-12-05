/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func reorderList(head *ListNode) {

    arr := []*ListNode{}
    start := head.Next
    for start != nil {
        arr = append(arr,start)
        start = start.Next
    }

    mh := head
    for len(arr) > 1 {
        mh.Next = arr[len(arr) - 1]
        arr = arr[:len(arr) - 1]
        mh = mh.Next
        mh.Next = arr[0]
        mh = mh.Next
        arr = arr[1:]
    }
    if len(arr) == 1 {
        mh.Next = arr[0]
        mh = mh.Next
    }    

    mh.Next = nil
}

