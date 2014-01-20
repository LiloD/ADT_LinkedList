/*
 * LinkedList.h
 *
 *  Created on: Jan 18, 2014
 *      Author: Zhizhuo
 */
#include <iostream>
#include "LinkedNode.h"

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

template<typename T> std::ostream& operator<< (std::ostream&, const LinkedList<T>&);

template<typename T>
class LinkedList
{
	friend std::ostream& operator<< <T> (std::ostream& os, const LinkedList<T> &t);
public:
	LinkedList():head(0),tail(0),size(0){}
	LinkedList(const T &t):head(0),tail(0),size(0){ copy_elems(t);}
	T& operator=(const T&);
	T& operator[](const int size_t);
	~LinkedList(){destroy();}
	void Append(const T&);
	void Insert(const T&,int index);
	void Delete(int index);
	int len(){return size;}
	T& gethead(){return head->item;}
	T& gettail(){return tail->item;}

private:
	LinkedNode<T> *head;
	LinkedNode<T> *tail;
	int size;
	void copy_elems(const T &);
	void destroy();
};



#endif /* LINKEDLIST_H_ */
