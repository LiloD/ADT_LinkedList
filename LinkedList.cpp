/*
 * LinkedList.cpp
 *
 *  Created on: Jan 18, 2014
 *      Author: Zhizhuo
 */
#include "LinkedList.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
void LinkedList<T>::copy_elems(const T &t)
{
	//head = t.head;
	LinkedNode<T> *ptr;
	for( ptr = t.head; ptr; ptr = ptr->next )
	{
		Append(ptr->item);
	}
	size = t.size;
}

template<typename T>
void LinkedList<T>::destroy()
{
	LinkedNode<T> *ptr,*tmp;
	if(head != NULL)
	{
		for( ptr = head; ptr!= NULL; )
		{
			ptr = ptr->next;
			tmp = ptr;
			delete tmp;
		}
	}
	head = tail = NULL;
	size = 0;
}

template<typename T>
void LinkedList<T>::Append(const T&t)
{
	LinkedNode<T> *newcell = new LinkedNode<T>(t);

	//if no elements in the linked list
	if(head == NULL)
	{
		head = newcell;
		tail = newcell;
		newcell->next = NULL;
		size++;
	}else{
		//add at the end of the linked list
		tail->next = newcell;
		tail = newcell;
		newcell->next = NULL;
		size++;
	}
}

template<typename T>
void LinkedList<T>::Insert(const T &obj,int index)
{
	//check the input
	if(index < 0 || index >= size)
	{
		throw out_of_range("out of range error");
	}else
	{
		//if insert at the head of the linked list
		if(index == 0)
		{
			LinkedNode<T> *newcell = new LinkedNode<T>(obj);
			if(tail == NULL)
				tail = newcell;

			newcell->next = head;
			head = newcell;
			++size;
			return;
		}

		LinkedNode<T> *ptr = head;
		//get the insert position
		while(index>1)
		{
			ptr = ptr->next;
			index--;
		}

		//create a node and insert in the position
		LinkedNode<T> *newcell = new LinkedNode<T>(obj);
		newcell->next = ptr->next;
		ptr->next = newcell;
		++size;
		return;
	}
}

template<typename T>
void LinkedList<T>::Delete(int index)
{
	if(index < 0 || index >= size)
	{
		throw out_of_range("out of range error");
	}else{
		//if delete the head
		if(index == 0)
		{
			//if this linked list has more than 1 element
			if(size>1)
			{
				LinkedNode<T> *tmp = head;
				head = head->next;
				delete tmp;
				--size;
				return;
			}else{
				LinkedNode<T> *tmp = head;
				head = tail = 0;
				delete tmp;
				--size;
				return;
			}
		}
		//if delete the tail
		if(index == size-1)
		{
			LinkedNode<T> *ptr = head;
			while(ptr->next != tail)
				ptr = ptr->next;
			tail = ptr;
			delete (ptr->next);
			tail->next = NULL;
			--size;
			return;
		}

		LinkedNode<T> *ptr = head;
		while(index>1)
			ptr = ptr->next;
		//ptr is the previous one right before the element we want to delete
		//tmp is the element we want to delete
		LinkedNode<T> *tmp = ptr->next;
		ptr->next = tmp->next;
		delete tmp;
		--size;
	}
}

template<typename T>
T& LinkedList<T>::operator=(const T& orig)
{
	if(this == &orig)
		return *this;
	destroy();
	copy_elems(orig);
	return *this;
}

template<typename T>
ostream& operator<< (ostream& os, const LinkedList<T> &t)
{
	LinkedNode<T> *ptr;
	if(t.head == NULL)
	{
		os<<"This is an empty Linked List";
		return os;
	}

	for(ptr = t.head; ptr; ptr = ptr->next)
	{
		os<<ptr->item<<" ";
	}
	return os;
}

template<typename T>
T& LinkedList<T>::operator[](const int index)
{
	LinkedNode<T> *ptr = head;
	int i = index;
	while(i>0)
	{
		ptr=ptr->next;
		--i;
	}
	return ptr->item;
}

int main()
{

	cout<<"Hello World Generic Programming "<<endl;
	return 0;
}



