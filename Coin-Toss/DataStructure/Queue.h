#pragma once

namespace DataStructure {
	template <class T>
	class Queue {
	private:
		T* q_firstElement;
		T* q_nextElement;
		Queue(T&);
		T traverseQue();
		~Queue();
	public:
	protected:
	};
}


