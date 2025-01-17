#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using namespace std;

// An object of type TreeNode holds three things: 
//		- an item (of type T)
//		- a left subtree
//		- a right subtree

template <typename T>
class TreeNode
{
public:
	TreeNode(T i, TreeNode<T>* l, TreeNode<T>* r);
	TreeNode(T i);
	~TreeNode();

	TreeNode<T> *insert(TreeNode<T>* tree, T item);
	void traverse();

	bool searchTree(T key);

private:
	// The three things held in a TreeNode
	T item;
	TreeNode<T> *left, *right;
};

template <typename T>
TreeNode<T>::TreeNode(T i, TreeNode<T>* l, TreeNode<T>* r)
	: item(i), left(l), right(r)
{
}

template <typename T>
TreeNode<T>::TreeNode(T i)
	: item(i), left(0), right(0)
{
}

template <typename T>
TreeNode<T>::~TreeNode()
{
	if (left) delete left;
	if (right) delete right;
}

template <typename T>
TreeNode<T>* TreeNode<T>::insert(TreeNode<T>* tree, T item)
{  
	// Inserts item in tree, and returns the new tree
	if (tree == 0)
		tree = new TreeNode<T>(item);
	else
		if (item < tree->item)
			tree->left = insert(tree->left, item);
		else
			tree->right = insert(tree->right, item);
	return tree;
}

template <typename T>
void TreeNode<T>::traverse()
{
	if (left != 0)
		left->traverse();
	cout << item << endl;
	if (right != 0)
		right->traverse();
}

template <typename T>
bool TreeNode<T>::searchTree(T key) 
{
	if (item == key) {
		return true;
	}
	if (left != NULL) {
		return left->searchTree(key);
	}
	if (right != NULL) {
		return right->searchTree(key);
	}
	return false;
}

#endif
