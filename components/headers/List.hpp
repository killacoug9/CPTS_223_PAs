#pragma once

#include "./Node.hpp"

template <class T>
class List {

public:
	/*
	List(Node<T>* newmpHead = nullptr, Node<T>* newpTail = nullptr);

	List(List<T>& copy);

	~List();

	bool insertFront(T& plan);// bool b = false;

	bool insertLast(T& plan);

	// precondition: queue must not be empty
	std::string dequeue();

	bool isEmpty();

	Node<T>* getNode() const;
	*/

	/*************************************************************
	* Function :  List
	* Date Created : Sun Mar 20 18:29:01 2022
	* Date Last Modified : Sun Mar 20 18:29:01 2022
	* Description : TBD
	* Input parameters : (Node<T>* newmpHead = nullptr, Node<T>* newpTail = nullptr);
	* Returns : 
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	List(Node<T>* newmpHead = nullptr, Node<T>* newpTail = nullptr);

	/*************************************************************
	* Function :  copy
	* Date Created : Sun Mar 20 18:29:01 2022
	* Date Last Modified : Sun Mar 20 18:29:01 2022
	* Description : TBD
	* Input parameters : (List<T>& copy);
	* Returns : 	
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	List(List<T>& copy);

	/*************************************************************
	* Function :  deconstructor
	* Date Created : Sun Mar 20 18:29:01 2022
	* Date Last Modified : Sun Mar 20 18:29:01 2022
	* Description : TBD
	* Input parameters : 
	* Returns : 	bool
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	~List();

	/*************************************************************
	* Function :  insertFront(T& p
	* Date Created : Sun Mar 20 18:29:01 2022
	* Date Last Modified : Sun Mar 20 18:29:01 2022
	* Description : TBD
	* Input parameters : (T& plan);// bool b = fal
	* Returns : 	bool
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	bool insertFront(T& plan);// bool b = false;

	/*************************************************************
	* Function :  insertLast(T& p
	* Date Created : Sun Mar 20 18:29:01 2022
	* Date Last Modified : Sun Mar 20 18:29:01 2022
	* Description : TBD
	* Input parameters : (T& plan);
	* Returns : 	bool
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	bool insertLast(T& plan);

	/*************************************************************
	* Function :  dequeue();
	* Date Created : Sun Mar 20 18:29:01 2022
	* Date Last Modified : Sun Mar 20 18:29:01 2022
	* Description : TBD
	* Input parameters : ();
	* Returns : 	std::string
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	std::string dequeue();

	/*************************************************************
	* Function :  isEmpty();
	* Date Created : Sun Mar 20 18:29:01 2022
	* Date Last Modified : Sun Mar 20 18:29:01 2022
	* Description : TBD
	* Input parameters : ();
	* Returns : 	bool
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	bool isEmpty();

	/*************************************************************
	* Function :  getNode() const;
	* Date Created : Sun Mar 20 18:29:01 2022
	* Date Last Modified : Sun Mar 20 18:29:01 2022
	* Description : TBD
	* Input parameters : () const;
	* Returns : 	Node<T>*
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	Node<T>* getNode() const;


private:
	Node<T>* mpHead;
	Node<T>* mpTail;

	void destroyList();
};


/*
class LinkedList
{
public:
    // constructor
    LinkedList();

    // copy constructor


    // destructor
    ~LinkedList();

    Node* getHead();

    Node* getTail();


private:
    Node* mmpHead;
    Node* mpTail;

};
*/