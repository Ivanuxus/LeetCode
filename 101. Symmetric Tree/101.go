package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func treeToElems(root *TreeNode, buffer []int) {
	treeToElems(root.Left, buffer)
	buffer[len(buffer)] = root.Val
	treeToElems(root.Right, buffer)
}
func makeTreeByArray(buffer [256]int) *TreeNode {
	correctedJ := 0
	var rootFirst *TreeNode = nil
	root := rootFirst
	for i := 0; i < len(buffer); i++ {
		root = &TreeNode{buffer[i], nil, nil}
		counter := 0
		for j := i + 1; j < len(buffer); j++ {
			if correctedJ > j {
				j = correctedJ
			}
			if counter == 0 {
				root.Left = &TreeNode{buffer[j], nil, nil}
				counter = counter + 1
			} else if counter == 1 {
				root.Right = &TreeNode{buffer[j], nil, nil}
				counter = 0
				correctedJ = j
				break
			}
		}
	}
	return rootFirst
}
func isSymmetric(root *TreeNode) bool {
	//leftPart := root.Left
	//rightPart := root.Right
	return true
}
func main() {
	buffer := [256]int{1, 2, 2, 3, 4, 4, 3}
	root := makeTreeByArray(buffer)
	fmt.Printf("%p , %d", root.Left, root.Val)
}
