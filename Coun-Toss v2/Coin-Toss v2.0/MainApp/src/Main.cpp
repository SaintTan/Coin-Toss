#pragma once
#include "ConsoleLog.h"
#include "DataManager.h"
#include "AVLTree.h"
#include "FileLog.h"
#include <string>

int main() {
	int number = 1;
	DataStruct::AVLTree<int> numberTree(number);

	for(int i = 0; i<10; i++) numberTree.insertNode(*(new int(i)));

	numberTree.printTree();

}