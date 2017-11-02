/*
 * BST.h
 *
 *  Created on: Oct 31, 2017
 *      Author: jetci_000
 */

#ifndef BST_H_
#define BST_H_

#include <cstddef>
 #include <iostream>
#include <cstdlib>
#include <string>
#include <assert.h>

using namespace std;
template <typename bstdata>
class BST {
private:
    struct Node {
        bstdata data;
        Node* leftchild;
        Node* rightchild;

        Node(bstdata newdata){ // NODE constructor
            data = newdata;
            leftchild = NULL;
            rightchild = NULL;
        }
    };

    Node* root;

    /**Private helper functions*/
    void insertNode(Node* root, bstdata data);
    //private helper function for insert
    //recursively inserts a value into the BST

    void inOrderPrint(ostream& out, Node* root) const;

    //void inOrderPrint(Node* root) const;
    //private helper function for inOrderPrint
    //recursively prints tree values in order from smallest to largest

    void preOrderPrint(ostream& out, Node* root) const;
    //private helper function for preOrderPrint
    //recursively prints tree values in pre order

    void postOrderPrint(ostream &out, Node* root) const;
    //private helper function for postOrderPrint
    //recursively prints tree values in post order

    void copyNode(Node* copy) const;
    //recursive helper function to the copy constructor

    void freeNode(Node* root);
    //private helper function for the destructor
    //recursively frees the memory in the BST

    bool searchNode(Node* root, bstdata data);
    //recursive helper function to search
    //returns whether the value is found in the tree

    bstdata minimum(Node* root) const;
    //recursive helper function to minimum
    //returns the minimum value in the tree

    bstdata maximum(Node* root) const;
    //recursive helper function to maximum
    //returns the maximum value in the tree

    Node* deleteNode(Node* root, bstdata data);
    //recursive helper function to remove
    //removes data from the tree

    void getSize(Node* root, int& size) const;
    //recursive helper function to the size function
    //calculates the size of the tree
    //stores the result in size

    int getHeight(Node* root) const;
    //recursive helper function to the height function
    //returns the height of the tree

public:

    /**constructors and destructor*/

    BST();
    //Instantiates a new BST

    BST(const BST &bst);
    //copy constructor

    //~BST();***********
    //deallocates the tree memory

    /**access functions*/

    bstdata minimum() const;
    //returns the minimum value in the BST
    //pre: !empty()

    bstdata maximum() const;
    //returns the maximum value in the BST
    //pre: !empty()

    bool isEmpty() const;
    //determines whether the BST is empty

    int getSize() const;
    //returns the size of the tree

    bstdata getRoot() const;
    //returns the value stored at the root of the BST
    //pre: !isEmpty()

    int getHeight() const;
    //returns the height of the tree

    bool search(bstdata data) const;
    //returns whether the data is found in the tree
    //pre: !isEmpty()

    /**manipulation procedures*/

    void insert(bstdata data);
    //inserts new data into the BST

    void remove(bstdata data);
    //removes the specified value from the tree
    //pre: data is located in the tree
    //pre: !isEmpty()

    /**additional functions*/

    void inOrderPrint(ostream& out) const;
    //void inOrderPrint() const;
    //calls the inOrderPrint function to print out the values
    //stored in the BST

    void preOrderPrint(ostream& out) const;
    //calls the reOrderPrint function to print out the values
    //stored in the BST

    void postOrderPrint(ostream& out) const;
    //calls the postOrderPrint function to print out the values
    //stored in the BST
};
#endif /* BST_H_ */

//private helper function for insert
//recursively inserts a value into the BST
template<typename bstdata>
BST<bstdata>::BST(){
	root = NULL;
}
template<typename bstdata>
void BST<bstdata>::insert(bstdata data){
	    if (root == NULL)// if root is empty
	    {
	        root = new Node(data); //if the tree is empty insert the value at the root
	    }
	    else
	    {
	        insertNode(root, data); //otherwise call the helper function, passing it the root
	    }
}
template<typename bstdata>
void BST<bstdata>::insertNode(Node* root, bstdata data){
	if (data == root->data)
		return;
	else if (data < root->data){ // should node go to the left
		if (root->leftchild == NULL) //if so is the left slot empty?
			root->leftchild = new Node(data);

		else return insertNode(root->leftchild, data); // start process over starting with left child
	}
	else{
	if(root->rightchild == NULL)
	root->rightchild = new Node(data);
	else
		return insertNode(root->rightchild, data);
	}
}
template <typename bstdata>
//void BST<bstdata>::inOrderPrint() const{
void BST<bstdata>::inOrderPrint(ostream& out) const{
	if (root==NULL)
		cout << "empty";
	else
	  //inOrderPrint(root);
	  inOrderPrint(out,root);
}
template<typename bstdata>
//void BST <bstdata>::inOrderPrint(Node* root) const{
void BST<bstdata>::inOrderPrint(ostream &out, Node* thisRoot) const{
if (thisRoot == NULL){
return;

}
else{
	inOrderPrint (out, thisRoot->leftchild);
	out << thisRoot->leftchild->data << " ";
	inOrderPrint (out, thisRoot->rightchild);
}
}
