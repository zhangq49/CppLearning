#ifndef AVL_TREE_H
#define AVL_TREE_H

template<class T>
class TreeNode {
public:
	TreeNode() : lson(NULL), rson(NULL), freq(1), height(0) {}
	T data;
	int hight;
	unsigned int freq;
	TreeNode *lson;
	TreeNode *rson;
};

template<class T>
class AVLTree {
private:
	TreeNode<T> *root;
	void insertTreeNode(TreeNode<T> * &node, T x);
	TreeNode<T> *findTreeNode(TreeNode<T> *node, T x);
	void deleteTreeNode(TreeNode<T> * &node, T x);
	void inorderTraversal(TreeNode<T> *node, T x);
	int height(TreeNode<T> *node);
	void singleRotateLeft(TreeNode<T> * &node);
	void singleRotateRight(TreeNode<T> * &node);
	void doubleRotateRL(TreeNode<T> * &node);
	void doubleRotateLR(TreeNode<T> * &node);
	int max(int a, int b);

public:
	AVLTree() : root(NULL) {}
	void insert(T x);
	TreeNode<T> *find(T x);
	void deleteNode(T x);
	void traversal();
};

#endif