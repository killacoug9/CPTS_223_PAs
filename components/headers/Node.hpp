#pragma once

#include <iostream>
#include <string>
#include <fstream>

#define EXERCISE_TYPE ExercisePlan
#define DIET_TYPE DietPlan

using std::cout;
using std::string;
using std::endl;
using std::ostream;
using std::istream;
using std::fstream;
using std::ofstream;
using std::ifstream;

class Data;


template<class T>
class Node {
public:

	/*************************************************************
	* Function :  Node
	* Date Created : Sun Mar 20 18:14:13 2022
	* Date Last Modified : Sun Mar 20 18:14:13 2022
	* Description : TBD
	* Input parameters : (T& plan = nullptr);
	* Returns : 
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	Node(T& plan = nullptr);

	/*************************************************************
	* Function :  plan
	* Date Created : Sun Mar 20 18:14:13 2022
	* Date Last Modified : Sun Mar 20 18:14:13 2022
	* Description : TBD
	* Input parameters : (T& plan, Node<T>* pNext, Node<T>* pPrev);
	* Returns : 	
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	Node(T& plan, Node<T>* pNext, Node<T>* pPrev);

	/*************************************************************
	* Function : Node
	* Date Created : Sun Mar 20 18:14:13 2022
	* Date Last Modified : Sun Mar 20 18:14:13 2022
	* Description : TBD
	* Input parameters : (Node<T>& copy);
	* Returns : 	
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	Node(Node<T>& copy);

	//~Node();

	// getters	
	/*************************************************************
	* Function :  getNextNode() const;
	* Date Created : Sun Mar 20 18:14:13 2022
	* Date Last Modified : Sun Mar 20 18:14:13 2022
	* Description : TBD
	* Input parameters : () const;
	* Returns : 	Node<T>*
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	Node<T>* getNextNode() const;

	/*************************************************************
	* Function :  getPrevNode()const;
	* Date Created : Sun Mar 20 18:14:13 2022
	* Date Last Modified : Sun Mar 20 18:14:13 2022
	* Description : TBD
	* Input parameters : ()const;
	* Returns : 	Node<T>*
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	Node<T>* getPrevNode()const;

	/*************************************************************
	* Function :  getPlan();
	* Date Created : Sun Mar 20 18:14:13 2022
	* Date Last Modified : Sun Mar 20 18:14:13 2022
	* Description : TBD
	* Input parameters : ();
	* Returns : 	T&
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	T& getPlan();

	// setters
	/*************************************************************
	* Function :  setNextPtr
	* Date Created : Sun Mar 20 18:14:13 2022
	* Date Last Modified : Sun Mar 20 18:14:13 2022
	* Description : TBD
	* Input parameters : (Node<T>* pMem);
	* Returns : 	void
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	void setNextPtr(Node<T>* pMem);

	/*************************************************************
	* Function :  setPrevPtr
	* Date Created : Sun Mar 20 18:14:13 2022
	* Date Last Modified : Sun Mar 20 18:14:13 2022
	* Description : TBD
	* Input parameters : (Node<T>* pMem);
	* Returns : 	void
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	void setPrevPtr(Node<T>* pMem);

	/*************************************************************
	* Function :  setPlan
	* Date Created : Sun Mar 20 18:14:13 2022
	* Date Last Modified : Sun Mar 20 18:14:13 2022
	* Description : TBD
	* Input parameters : (T& plan);
	* Returns : 	void
	* Preconditions : TBD
	* Postconditions : TBD
	*************************************************************/
	void setPlan(T& plan);

private:
	T plan;
	Node<T>* mpNext;
	Node<T>* mpPrev;
};


