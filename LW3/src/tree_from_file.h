#ifndef TREE_NODE_H
#define TREE_NODE_H



#include <iostream>

/**
 * <h2>TreeNode</h2>
 * src/tree_node.h
 * src/tree_node.cpp
 * 
 * Tree is N-dimensional tree.
 **/

// types of directions
#define CRL_TRAVERSAL 0
#define CLR_TRAVERSAL 1
#define RLC_TRAVERSAL 2
#define LRC_TRAVERSAL 3

// types of traversals
#define INORDER_TRAVERSAL 0
#define PREORDER_TRAVERSAL 1
#define POSTORDER_TRAVERSAL 2
#define LEVELORDER_TRAVERSAL 3



template <typename KEY_TYPE, typename VALUE_TYPE>
class TreeNode {
private:
	VALUE_TYPE value_;
	KEY_TYPE key_; /**< name of node */
	Node* parent_;
	Node** children_; /**< subnodes */
	unsigned int childrenNum_; /**< num of subnodes */

	/** 
	 * In ...Traversal functions there is value direction, it must be char[] = "{1, 2, 3, 4, 5}",
	 * or we can call it permutation of array with numbers [0, branchesNum_ - 1]
	 **/
	VALUE_TYPE& inorderTraversal(Node<TYPE>* node, uint8_t direction, int (*dataProcessor)(TYPE value));
	VALUE_TYPE& preorderTraversal(Node<TYPE>* node, uint8_t direction, int (*dataProcessor)(TYPE value));
	VALUE_TYPE& postorderTraversal(Node<TYPE>* node, uint8_t direction, int (*dataProcessor)(TYPE value));
	VALUE_TYPE& levelorderTraversal(Node<TYPE>* node, uint8_t direction, int (*dataProcessor)(TYPE value));
public:
	Node();
	Node(Node<KEY_TYPE, VALUE_TYPE>* tree);

	void addNode(KEY_TYPE key, VALUE_TYPE value);

	/**
	 * dataProcessor() - function which choose what we must do with this data:
	 *   0) <b>return 0</b> - nothing, go to next (or function will do it on it's own)
	 *   1) <b>return 1</b> - return value and stop the process of traversal
	 **/
	Node* traversal(uint8_t type, uint8_t direction, uint8_t (*dataProcessor)(TYPE value));
	VALUE_TYPE value();
	KEY_TYPE key();

	unsigned int width() {
		return 
	}

	TreeNode& operator [] (unsigned int index);
	/** return true if there is this node and false if it are not there,
	 * set <b>node</b> on found node **/
	TreeNode& operator () (KEY_TYPE key, TreeNode* node);

	~Node();
};



#endif