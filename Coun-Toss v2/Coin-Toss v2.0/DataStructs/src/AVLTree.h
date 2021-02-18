#pragma once

namespace DataStruct {
	template <class T>
	struct AVLnode {
	private:
		T& data;
		AVLnode<T>* left;
		AVLnode<T>* right;
		AVLnode<T>* parent;
	public:
		AVLnode(T& data);
		AVLnode(T& data, AVLnode& parentNode);
		void updateParent(AVLnode* newParent);
		void updateLeft(AVLnode* newLeft);
		void updateRight(AVLnode* newRight);
		void updateAll(AVLnode& newParent, AVLnode& newLeft, AVLnode& newRight);
		T& getData();
		AVLnode<T>* getParent();
		AVLnode<T>* getLeft();
		AVLnode<T>* getRight();

	};

	template <class T>
	class AVLTree {
	private:
		AVLnode<T>* startNode;
	public:
		AVLTree(T&);
		void insertNode(T& newNode);
		void printTree();
		
	//	&T searchNode(AVLnode<T>&);
	//	void deleteNode(AVLnode<T>&);
	private:
		void rotateLeft(AVLnode<T>* node);
		void rotateRight(AVLnode<T>* node);	
		void insertNode(T& newNode, AVLnode<T>* parentNode);
		void printTree(AVLnode<T>* node);
		int findImbal(AVLnode<T>* node);
		
	};
}

//instantiation

template <class T>
DataStruct::AVLnode<T>::AVLnode(T& data) : data(data), left(NULL), right(NULL), parent(NULL) {};

template <class T>
DataStruct::AVLnode<T>::AVLnode(T& data, AVLnode<T>& node) : data(data), left(NULL), right(NULL), parent(&node) {}

template<class T>
DataStruct::AVLTree<T>::AVLTree(T& data) : startNode(new AVLnode<T>(data)) {};

//AVLTree implementation

template<class T>
void DataStruct::AVLTree<T>::insertNode(T& newData) {
	insertNode(newData, startNode);
	return;
}

template<class T>
void DataStruct::AVLTree<T>::insertNode(T& newData, AVLnode<T>* parentNode) {
	if (!parentNode) return;
	if (newData > parentNode->getData()) {
		if (!parentNode->getRight()) {
			AVLnode<T>* newNode = new AVLnode<T>(newData, *parentNode);
			parentNode->updateRight(newNode);
		}
		else insertNode(newData, parentNode->getRight());
	}
	else {
		if (!parentNode->getLeft()) {
			AVLnode<T>* newNode = new AVLnode<T>(newData, *parentNode);
			parentNode->updateLeft(newNode);
		}
		else insertNode(newData, parentNode->getLeft());
	}
	int balance = findImbal(parentNode);
	//left side imbalance
	if (balance < -1) {
		balance = findImbal(parentNode->getLeft());
		if (balance > 0) rotateLeft(parentNode->getLeft());
		rotateRight(parentNode);
	}
	//right side imbalance
	else if (balance > 1) {
		balance = findImbal(parentNode->getRight());
		if (balance < 0) rotateRight(parentNode->getRight());
		rotateLeft(parentNode);
	}
};

template<class T>
int DataStruct::AVLTree<T>::findImbal(AVLnode<T>* node) {
	if (node == NULL) return 1;
	return findImbal(node->getLeft()) - findImbal(node->getRight());
}

template<class T>
void DataStruct::AVLTree<T>::rotateLeft(AVLnode<T>* node) {
	AVLnode<T>* targetNode = node->getRight();
	if (!node->getParent()) {
		startNode = node;
		node->updateParent(NULL);
	}
	else {
		if (node->getParent()->getLeft() == node) {
			node->getParent()->updateLeft(targetNode);
		}
		else {
			node->getParent()->updateRight(targetNode);
		}
	}
	
	targetNode->updateParent(node->getParent());
	node->updateRight(targetNode->getLeft());
	node->updateParent(targetNode);
	if(targetNode->getLeft()) targetNode->getLeft()->updateParent(node);
	targetNode->updateLeft(node);
}

template<class T>
void DataStruct::AVLTree<T>::rotateRight(AVLnode<T>* node) {
	AVLnode<T>* targetNode = node->getLeft();
	if (!node->getParent()) {
		startNode = node;
		node->updateParent(NULL);
	}
	else {
		if (node->getParent()->getLeft() == node) {
			node->getParent()->updateLeft(targetNode);
		}
		else {
			node->getParent()->updateRight(targetNode);
		}
	}
	targetNode->updateParent(node->getParent());
	node->updateLeft(targetNode->getRight());
	node->updateParent(targetNode);
	if (targetNode->getRight()) targetNode->getRight()->updateParent(node);
	targetNode->updateRight(node);
}

template <class T>
void DataStruct::AVLnode<T>::updateParent(AVLnode<T>* node) {
	if (node) this->parent = node;
	else this->parent = NULL;
}

template <class T>
void DataStruct::AVLnode<T>::updateLeft(AVLnode<T>* node) {
	if (node) this->left = node;
	else this->left = NULL;
}

template <class T>
void DataStruct::AVLnode<T>::updateRight(AVLnode<T>* node) {
	if (node) this->right = node;
	else this->right = NULL;
}

template <class T>
void DataStruct::AVLnode<T>::updateAll(AVLnode<T>& newParent, AVLnode<T>& newLeft, AVLnode<T>& newRight) {
	this->parent = &newParent;
	this->left = &newLeft;
	this->right = &newRight;
}

template <class T>
T& DataStruct::AVLnode<T>::getData() {
	return data;
}

template <class T>
DataStruct::AVLnode<T>* DataStruct::AVLnode<T>::getParent() {
	return parent;
}

template <class T>
DataStruct::AVLnode<T>* DataStruct::AVLnode<T>::getLeft() {
	return left;
}

template <class T>
DataStruct::AVLnode<T>* DataStruct::AVLnode<T>::getRight() {
	return right;
}

template<class T>
void DataStruct::AVLTree<T>::printTree() {
	printTree(startNode);
}

template <class T>
void DataStruct::AVLTree<T>::printTree(AVLnode<T>* node) {
	if (!node) return;
	printTree(node->getLeft());
	printTree(node->getRight());
}
