#pragma once
namespace DataStruct {
	template <class T>
	struct AVLnode {
	private:
		T& data;
		AVLnode* left;
		AVLnode* right;
		AVLnode* parent;
	public:
		AVLnode(T&);
	};

	template <class T>
	class AVLTree {
	private:
		AVLnode<T>* startNode;
	public:
		AVLTree(T&);
	/*	void insertNode(AVLnode<T>&);
		T searchNode(AVLnode<T>&);
		void deleteNode(AVLnode<T>&);
	private:
		void rotateLeft(AVLnode<T>&);
		void rotateRight(AVLnode<T>&);
	*/	
	};
}

template<class T>
DataStruct::AVLnode<T>::AVLnode(T& data) : data(data), left(NULL), right(NULL), parent(NULL) {};

template<class T>
DataStruct::AVLTree<T>::AVLTree(T& data) : startNode(new AVLnode<T>(data)) {};
