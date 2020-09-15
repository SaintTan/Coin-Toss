#include "Queue.h"

template<class T>
DataStructure::Queue<T>::Queue(T& element): q_firstElement(*element), q_nextElement(nullptr) {}