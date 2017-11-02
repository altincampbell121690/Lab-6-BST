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

	cout << "!!!*Hello World*!!!" << endl; // prints !!!Hello World!!!
	BST<int>tree1;
	tree1.insert(5);
	tree1.insert(2);
	tree1.insert(6);
	tree1.insert(1);
	tree1.insert(0);
	tree1.inOrderPrint(cout);

	cout << "!!!*Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
