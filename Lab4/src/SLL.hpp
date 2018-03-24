/*
 * SLL.hpp
 *
 *  Created on: Mar 23, 2018
 *      Author: shawnegan
 */

#ifndef SLL_HPP_
#define SLL_HPP_

#include "SNode.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;

class SLL {
	friend class WebTopic;
	SNode *first;
	SNode *last;
	SNode *p2;
	int size;
public:
	SLL();
	~SLL();
	void printSLL();
	void priorityInsert(string s, int p);
	void push(string s, int p);
	void addAtFront(string s, int p);
	void addFirst(string s, int p);
	void addAtP2(string s, int p);
	int removeAll(string w);
	string pop();
};

#endif /* SLL_HPP */
