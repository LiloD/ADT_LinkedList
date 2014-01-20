/*
 * LinkedNode.h
 *
 *  Created on: Jan 18, 2014
 *      Author: Zhizhuo
 */
#include <iostream>
#include <ostream>

#ifndef LINKEDNODE_H_
#define LINKEDNODE_H_

template<typename T> class LinkedList;
template<typename T> std::ostream& operator<< (std::ostream&, const LinkedList<T>&);

template<typename T>
class LinkedNode
{
	friend class LinkedList<T>;
	friend std::ostream& operator<< <T> (std::ostream&, const LinkedList<T> &);
	T item;
	LinkedNode *next;
	LinkedNode(const T &t):item(t),next(0){}
};

#endif /* LINKEDNODE_H_ */
