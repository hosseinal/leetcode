/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func recNodeChanger(root *TreeNode) *TreeNode{
    
    if root == nil {
        return nil
    }
    
    node := TreeNode{
        Val : root.Val,
    }

    node.Left = recNodeChanger(root.Right)
    node.Right = recNodeChanger(root.Left) 
    
    return &node
}

func invertTree(root *TreeNode) *TreeNode {

    if root == nil {
        return nil
    }

    node := TreeNode {
        Val : root.Val,
    }

    node.Left = recNodeChanger(root.Right)
    node.Right = recNodeChanger(root.Left) 
    
    return &node
}

