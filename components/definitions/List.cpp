#include "./headers/List.hpp"

template <class T>
List<T>::List(Node<T>* newpHead, Node<T>* newpTail) {
	this->mpHead = newpHead; // pointer assignment
	this->mpTail = newpTail;
}

template <class T>
List<T>::List(List<T>& copy) {
	setHead(copy.getHead());
	setTail(copy.getTail());
}

template <class T>
List<T>::~List() {
	destroyList();
}

template <class T>
bool List<T>::isEmpty() {
	return this->mpHead == nullptr;
}

template <class T>
bool List<T>::insertFront(T& plan) {
	Node<T>* pMem = new Node<T>(plan);
	bool success = false;

	if (pMem != nullptr) {
		success = true;

		if (isEmpty()) {
			this->mpHead = this->mpTail = pMem;
		}
		else {
			// not empty queue
			this->mpHead->setPrevPtr(pMem);
			pMem->setNextPtr(this->mpHead);
			this->mpHead = pMem;

		}
	}
	return success;
}

template <class T>
bool List<T>::insertLast(T& plan) {
	Node<T>* pMem = new Node<T>(plan);
	bool success = false;

	if (pMem != nullptr) {
		success = true;

		if (isEmpty()) {
			this->mpHead = this->mpTail = pMem;
		}
		else {
			// not empty queue
			this->mpTail->setNextPtr(pMem);
			pMem->setPrevPtr(this->mpTail);
			this->mpTail = pMem;
		}
	}
	return success;
}


// mostly used to destroy the list
template <class T>
std::string List<T>::dequeue() {

	Node<T>* pTemp = this->mpHead;

	// one node in queue
	if (this->mpHead == this->mpTail) {

		this->mpHead = this->mpTail = nullptr;
	}
	else {
		this->mpHead = this->mpHead->getNextNode();
	}

	std::string data = pTemp->getPlan().getDate();

	//std::string data = "string";
	delete pTemp; // default deconstructor for a node is invoked
	return data;
}

// private member function
template <class T>
void List<T>::destroyList() {
	//delete this;
	while (!isEmpty()) {
		dequeue();
		//delete this->pHead;
	}
}

template <class T>
Node<T>* List<T>::getNode() const {
	return this->pHead;
}

