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
    }
    return b
}

func isBalanced(root *TreeNode) bool {
    
    balanced := true
    var dfs func(root *TreeNode) int 
    dfs = func (root *TreeNode) int {
        if root == nil {
            return 1
        }

        ld := dfs(root.Left) + 1
        rd := dfs(root.Right) + 1

        if ld > rd + 1 || rd > ld +1 {
            balanced = false
        }
        
        return max(ld,rd)

    }   

    dfs(root)

    return balanced

}

