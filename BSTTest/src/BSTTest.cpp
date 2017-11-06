//============================================================================
// Name        : BSTTest.cpp
// Author      : Altin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "BST.h"
#include <iostream>
#include <ostream>
using namespace std;

int main() {
	BST<int> tree1;
	//BST<string>tree2;
//**
	cout << "!!!*Hello World*!!!" << endl; // prints !!!Hello World!!!
	//testing insert
	tree1.insert(40);
	tree1.insert(25);
	tree1.insert(78);
	//tree1.insert(3);
	tree1.insert(10);
	tree1.insert(32);
	//testing Inorder print
	//tree1.inOrderPrint(cout);
	//testing postrder print
	tree1.postOrderPrint(cout);
///**/

	cout << tree1.getSize() << endl;
	//test is empty
	cout << "should print: not empty\n";
	if (tree1.isEmpty())
		cout << "it is empty\n";
	else
		cout << "not empty\n";
	cout << "should print: Found\n";
	if (tree1.search(32))
		cout << "FOUND: 32\n";
	else
		cout << "not HERE\n";
	cout << "should print: not HERE\n";
	if (tree1.search(15))
		cout << "FOUND\n";
	else
		cout << "not HERE\n";
	cout << "!!!*Hello World**~!!!" << endl; // prints !!!Hello World!!!
	cout << "The size of the tree is: " << tree1.getSize() << endl;

		cout << "The minimum value of the tree is: " << tree1.minimum() << endl;

		cout << "The maximum value of the tree is: " << tree1.maximum() << endl;

		cout << "The height of the tree is: " << tree1.getHeight() << endl;

		//tree1.remove(10);
		tree1.preOrderPrint(cout);
		BST<int>tree2(tree1);
		tree2.preOrderPrint(cout);
		cout << "The size of tree1 is :" << tree1.getSize() << endl;
		cout << "The size of tree2 is :" << tree2.getSize() << endl;
		return 0;
	}
