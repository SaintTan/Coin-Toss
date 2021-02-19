#pragma once
#include "ConsoleLog.h"
#include "DataManager.h"
#include "AVLTree.h"
#include "FileLog.h"
#include <string>
#include <iostream>


template <typename T >
void printThings(T data) {
	std::cout << data << std::endl;
}

int main() {
	int number = 10;
	DataStruct::AVLTree<int> numberTree(number);

	for(int i = 0; i<10; i++) numberTree.insertNode(*(new int(i)));

	numberTree.workTree(printThings);

	std::cout << (numberTree.searchNode(number)->getData()) << std::endl;
}

