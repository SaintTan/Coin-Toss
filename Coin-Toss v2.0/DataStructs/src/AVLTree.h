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
		void checkNUpdate (AVLnode* targetNode);
		void updateAll(AVLnode* newParent, AVLnode* newLeft, AVLnode* newRight);
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
		void insertNode(T& data);
		void deleteNode(T& data);
		AVLnode<T>* searchNode(T& data);
		void workTree(void (*passedFunc)(T&));
	private:
		void rotateLeft(AVLnode<T>* node);
		void rotateRight(AVLnode<T>* node);	
		void insertNode(T& data, AVLnode<T>* parentNode);
		void balanceAlgo(AVLnode<T>* node);
		int findHeight(AVLnode<T>* node);
		int findImbal(AVLnode<T>* node);
		void deleteNode(T& data, AVLnode<T>* node);
		AVLnode<T>* searchNode(T& data, AVLnode<T>* node);
		AVLnode<T>* searchMinimum(AVLnode<T>* node);
		void workTree(AVLnode<T>* node, void (*passedFunc)(T&));
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
	balanceAlgo(parentNode);
};

template<class T>
void DataStruct::AVLTree<T>::deleteNode(T& data) {
	deleteNode(data, startNode);
}

template<class T>
void DataStruct::AVLTree<T>::deleteNode(T& data, AVLnode<T>* targetNode) {
	if (data > targetNode->getData()) {
		deleteNode(data, targetNode->getRight());
	}
	else if (data < targetNode->getData()) {
		deleteNode(data, targetNode->getLeft());
	}
	else if (data == targetNode->getData()) {
		if (!targetNode->getLeft() && !targetNode->getRight()) {
			targetNode->checkNUpdate(NULL);
		}

		else if (!targetNode->getLeft() && targetNode->getRight()) {
			targetNode->checkNUpdate(targetNode->getRight());
		}

		else if (!targetNode->getRight() && targetNode->getLeft()) {
			targetNode->checkNUpdate(targetNode->getLeft());
		}

		else {
			AVLnode<T>* minimumNode = searchMinimum(targetNode->getRight());
			if (!targetNode->getParent()) startNode = minimumNode;
			else targetNode->checkNUpdate(minimumNode);
			if (targetNode->getLeft()) targetNode->getLeft()->updateParent(minimumNode);
			if (targetNode->getRight()) targetNode->getRight()->updateParent(minimumNode);
			if (minimumNode->getParent()) minimumNode->checkNUpdate(NULL);
			minimumNode->updateLeft(targetNode->getLeft());
			minimumNode->updateRight(targetNode->getRight());
			minimumNode->updateParent(targetNode->getParent());
		}
		delete targetNode;
		return;
	}
	balanceAlgo(targetNode);
	return;

}

template<class T>
int DataStruct::AVLTree<T>::findHeight(AVLnode<T>* node) {
	if (!node) return 0;
	int left = findHeight(node->getLeft());
	int right = findHeight(node->getRight());
	return(1 + (left > right ? left : right));
}

template<class T>
int DataStruct::AVLTree<T>::findImbal(AVLnode<T>* node) {
	return findHeight(node->getLeft()) - findHeight(node->getRight());
}

template<class T>
void DataStruct::AVLTree<T>::balanceAlgo(AVLnode<T>* node) {
	int balance = findImbal(node);
	//left side imbalance
	if (balance > 1) {
		balance = findImbal(node->getLeft());
		if (balance < 0) rotateLeft(node->getLeft());
		rotateRight(node);
	}
	//right side imbalance
	else if (balance < -1) {
		balance = findImbal(node->getRight());
		if (balance > 0) rotateRight(node->getRight());
		rotateLeft(node);
	}
}

template<class T>
DataStruct::AVLnode<T>* DataStruct::AVLTree<T>::searchNode(T& data) {
	return searchNode(data, startNode);
}

template<class T>
DataStruct::AVLnode<T>* DataStruct::AVLTree<T>::searchNode(T& data, AVLnode<T>* node) {
	if (data > node->getData()) {
		return searchNode(data, node->getRight());
	}
	else if (data < node->getData()) {
		return searchNode(data, node->getLeft());
	}
	else if (data == node->getData()) {
		return node;
	}

	return NULL;
}

template<class T>
void DataStruct::AVLTree<T>::rotateLeft(AVLnode<T>* node) {
	AVLnode<T>* targetNode = node->getRight();
	
	
	targetNode->updateParent(node->getParent());
	node->updateRight(targetNode->getLeft());
	if(targetNode->getLeft()) targetNode->getLeft()->updateParent(node);
	targetNode->updateLeft(node);

	if (!node->getParent()) {
		startNode = targetNode;
	}
	else {
		node->checkNUpdate(targetNode);
	}
	node->updateParent(targetNode);
}

template<class T>
void DataStruct::AVLTree<T>::rotateRight(AVLnode<T>* node) {
	AVLnode<T>* targetNode = node->getLeft();
	
	targetNode->updateParent(node->getParent());
	node->updateLeft(targetNode->getRight());
	if (targetNode->getRight()) targetNode->getRight()->updateParent(node);
	targetNode->updateRight(node);

	if (!node->getParent()) {
		startNode = targetNode;
	}
	else {
		node->checkNUpdate(targetNode);
	}
	node->updateParent(targetNode);
}

template<class T>
void DataStruct::AVLnode<T>::checkNUpdate(AVLnode<T>* targetNode) {
	if (this->getParent()->getLeft() == this) {
		this->getParent()->updateLeft(targetNode);
	}
	else {
		this->getParent()->updateRight(targetNode);
	}
}

template<class T>
DataStruct::AVLnode<T>* DataStruct::AVLTree<T>::searchMinimum(AVLnode<T>* node) {
	if (!node->getLeft()) return node;
	return(searchMinimum(node->getLeft()));
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
void DataStruct::AVLnode<T>::updateAll(AVLnode<T>* newParent, AVLnode<T>* newLeft, AVLnode<T>* newRight) {
	this->parent = newParent;
	this->left = newLeft;
	this->right = newRight;
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
void DataStruct::AVLTree<T>::workTree(void (*passedFunc)(T&)) {
	workTree(startNode, passedFunc);
}

template <class T>
void DataStruct::AVLTree<T>::workTree(AVLnode<T>* node, void (*passedFunc)(T&)) {
	if (!node) return;
	workTree(node->getLeft(), passedFunc);
	passedFunc(node->getData());
	workTree(node->getRight(), passedFunc);
}
