/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isSameTree(p *TreeNode, q *TreeNode) bool {
    qs := []int{}
    ps := []int{}
    
    // 1. Change the signature to return []int
    var stackFiller func(node *TreeNode ,arr []int) []int 
    
    stackFiller = func(node *TreeNode ,arr []int) []int {
        if node == nil {
            arr = append(arr,-1000)
            return arr 
        }

        arr = append(arr,node.Val)
        
       
        arr = stackFiller(node.Left, arr) 
        arr = stackFiller(node.Right, arr)
        
        return arr 
    }

    ps = stackFiller(p, ps)
    qs = stackFiller(q, qs)

    if len(ps) != len(qs){
        return false
    }

    for i:=0; i < len(ps); i++{
        if qs[i] != ps[i]{
            return false
        }
    }

    return true
}

