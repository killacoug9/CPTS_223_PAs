#include "../headers/Node.hpp"


// Definitions Below

//constructor 1
template<class T>
Node<T>::Node(T& plan) {
	//T plan(this);
	this->plan = plan;
	this->mpNext = nullptr;
	this->mpPrev = nullptr;
}

//constructor 2(overloaded)
template<class T>
Node<T>::Node(T& plan, Node<T>* pNext, Node<T>* pPrev) {
	this->plan = plan;
	this->mpNext = pNext;
	this->mpPrev = pPrev;
}

template<class T>
Node<T>::Node(Node<T>& copy){
	setPlan(copy.getPlan());
	setNextPtr(copy.getNextPtr());
	setPrevPtr(copy.getPrevPtr());
}

// empty ??
//template<class T>
//Node<T>::~Node() {}

// getters	
template<class T>
Node<T>* Node<T>::getNextNode() const { return this->mpNext; }

template<class T>
Node<T>* Node<T>::getPrevNode()const { return this->mpPrev; }

template<class T>
T& Node<T>::getPlan() { return this->plan; }


// setters
template<class T>
void Node<T>::setNextPtr(Node<T>* pMem) { this->mpNext = pMem; }

template<class T>
void Node<T>::setPrevPtr(Node<T>* pMem) { this->mpPrev = pMem; }

template<class T>
void Node<T>::setPlan(T& plan) { this->plan = plan; }

//template<class T>
//ostream& operator<<(ostream& lhs, Node<T>& rhs);
