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



template <typename KEY_TYPE, typename VALUE_TYPE>
class TreeNode {
private:
	VALUE_TYPE value_;
	KEY_TYPE key_; /**< name of node */
	TreeNode* parent_;
	TreeNode** children_; /**< subnodes */
	unsigned int childrenNum_; /**< num of subnodes */
public:
	TreeNode();
	TreeNode(KEY_TYPE key, VALUE_TYPE value);
	TreeNode(TreeNode<KEY_TYPE, VALUE_TYPE>* tree);

	void addNode(KEY_TYPE key, VALUE_TYPE value);

	VALUE_TYPE value() const;
	KEY_TYPE key() const;
	unsigned int width() const;

	/**
	 * dataProcessor():
	 * function which choose what we must do with this data:
	 *   0) <b>return 0</b> - nothing, go to next (or function will do it on it's own)
	 *   1) <b>return 1</b> - stop the process of traversal
	 * 
	 * direction:
	 *  1) CRL - CRL_TRAVERSAL
	 *  2) CLR - CLR_TRAVERSAL
	 *  3) RLC - RLC_TRAVERSAL
	 *  4) LRC - LRC_TRAVERSAL
	 **/
	int traversal(uint8_t direction, int (*dataProcessor)(VALUE_TYPE* value));

	/** return true if there is this node and false if it are not there,
	 * set <b>node</b> on found node **/
	bool find(KEY_TYPE key, TreeNode* node);

	TreeNode& operator [] (unsigned int index);

	void operator = (TreeNode<KEY_TYPE, VALUE_TYPE>& tree);

	~TreeNode();

	friend class TreeNode;
};



#endif