/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func max(a,b int) int{
    if a > b {
        return a
    }else {
        return b
    }
}

func maxFinder(node *TreeNode,m *int) int{
    if node == nil {
        return 0
    }

    left := maxFinder(node.Left, m)
    right := maxFinder(node.Right, m)
    *m = max(*m, left+ right)
    
    return 1 + max(left,right)
}

func diameterOfBinaryTree(root *TreeNode) int {
    var max = 0

    maxFinder(root, &max)

    return max
}
 
