#include "avltree.h"

// calculate the height of a tree
template<class T>
int AVLTree<T>::height(TreeNode<T> *node) {
	if (node != NULL)
		return node->height;
	return -1;
}

// calculate the maximum of two integers
template<class T>
int AVLTree<T>::max(int a, int b) {
	return (a > b ? a : b);
}

// rotate when the tree is under left-left imbalance
template<class T>
void AVLTree<T>::singleRotateL(TreeNode<T> * &node) {
	TreeNode<T> *
}

// insert a new data into a tree
template<class T>
void AVLTree<T>::insertTreeNode(TreeNode<T> * &node, T x) {
	if (node == NULL) {
		node = new TreeNode<T>();
		node.data = x;
		return;
	}

	if (node->data < x) {
		insertTreeNode(node->lson, x);
		if (2 == height(node->lson) - height(node->rson))
			if (x < node->lson->data)
				singleRotateL(node);
			else
				doubleROtateLR(node);
	} else if (node->data > x) {
		insertTreeNode(node->rson, x);
		if (2 == height(node->rson) - height(node->lson))
			if (x > node->rson->data)
				singleRotateR(node);
			else
				doubleRotateRL(node);
	} else {
		++(node->freq);
	}

	node->height = max(height(node->lson), height(node->rson));
}

