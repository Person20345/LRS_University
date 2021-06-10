#include <iostream>



#include "tree_node.cpp"



template <typename KEY_TYPE, typename VALUE_TYPE>
TreeNode<KEY_TYPE, VALUE_TYPE>::TreeNode() {
	parent_ = nullptr;
	branchesNum_ = 0;
}



template <typename KEY_TYPE, typename VALUE_TYPE>
TreeNode<KEY_TYPE, VALUE_TYPE>::TreeNode(KEY_TYPE key, VALUE_TYPE value) {
	value_ = value;
	key_ = key;
}



template <typename KEY_TYPE, typename VALUE_TYPE>
TreeNode<KEY_TYPE, VALUE_TYPE>::TreeNode(TreeNode<KEY_TYPE, VALUE_TYPE>* tree) {
	*this = *tree;
}



template <typename KEY_TYPE, typename VALUE_TYPE>
void TreeNode<KEY_TYPE, VALUE_TYPE>::addNode(KEY_TYPE key, VALUE_TYPE value) {
	childrenNum_++;
	
	TreeNode** updatedChildren = (TreeNode**) new TreeNode*[childrenNum_];
	for (int i = 0; i < childrenNum_ - 1; i++)
		updatedChildren[i] = children_[i];
	updatedChildren[childrenNum_ - 1] = (TreeNode*) new TreeNode(key, value);
	parent_ = this;

	delete[] children_;

	children_ = updatedChildren;
}



template <typename KEY_TYPE, typename VALUE_TYPE>
VALUE_TYPE Node<KEY_TYPE, VALUE_TYPE>::value() const {
	return value_;
}



template <typename KEY_TYPE, typename VALUE_TYPE>
KEY_TYPE Node<KEY_TYPE, VALUE_TYPE>::key() const {
	return key_;
}



template <typename KEY_TYPE, typename VALUE_TYPE>
unsigned int Node<KEY_TYPE, VALUE_TYPE>::width() const {
	return childrenNum_;
}



template <typename KEY_TYPE, typename VALUE_TYPE>
int Node<KEY_TYPE, VALUE_TYPE>::traversal(uint8_t direction, int (*dataProcessor)(VALUE_TYPE* value)) {
	if (direction == CRL_TRAVERSAL || direction == CLR_TRAVERSAL) {
		int ret = (*dataProcessor)(value_);
		if (ret != 0)
			return ret;
	}

	int startIndex, endIndex, delta;
	if (direction == CRL_TRAVERSAL || direction == RLC_TRAVERSAL) {
		startIndex = 0;
		endIndex = childrenNum_ - 1;
		delta = 1;
	} else if (direction == CLR_TRAVERSAL || direction == LRC_TRAVERSAL) {
		startIndex = childrenNum_ - 1;
		endIndex = 0;
		delta = -1;
	}

	for (i = startIndex; i <= endIndex; i += delta) {
		ret = children_[i]->inorderTraversal(direction, dataProcessor);
		if (ret != 0)
			return ret;
	}

	if (direction == RLC_TRAVERSAL || direction == LRC_TRAVERSAL) {
		int ret = (*dataProcessor)(value_);
		if (ret != 0)
			return ret;
	}
	return 0;
}



template <typename KEY_TYPE, typename VALUE_TYPE>
bool Node<KEY_TYPE, VALUE_TYPE>::find(KEY_TYPE key, TreeNode* node) {
	long i;
	bool find = false;
	for (i = 0; i < childrenNum_; i++)
		if (children_[i]->key() == key) {
			node = children_[i];
			return true;
		}

	return false;
}



template <typename KEY_TYPE, typename VALUE_TYPE>
TreeNode& Node<KEY_TYPE, VALUE_TYPE>::operator [] (unsigned int index) {
	try {
   if (index < childrenNum_)
      throw "Index out of range";
  } catch (const char* exception) {
      std::cerr << "Error: " << exception << '\n';
      exit(1);
  }

	return *children_[index];
}



void operator = (TreeNode<KEY_TYPE, VALUE_TYPE>& tree) {
	this->value_ = tree.value();
	this->key-> = tree.key();
	this->childrenNum_ = tree.width();
	this->children_ = (TreeNode**) new TreeNode*[this->childrenNum_];
	for (int i = 0; i < childrenNum_; i++)
		*(this->children_[i]) = tree[i];
}



template <typename KEY_TYPE, typename VALUE_TYPE>
TreeNode<KEY_TYPE, VALUE_TYPE>::~TreeNode() {
	for(int i = 0; i < childrenNum_; i++)
		delete children_[i];

	delete[] children_;
	delete children_;
}


int main() { return 0; }