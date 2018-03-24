/*
 * SLL.cpp
 *
 *  Created on: Mar 23, 2018
 *      Author: shawnegan
 */

#include "SLL.hpp"

using namespace std;

SLL::SLL() {
	first = NULL;
	last = NULL;
	size = 0;
	p2 = NULL;
}

SLL::~SLL() {
	delete first;
	delete last;
	delete p2;

}

void SLL::printSLL() {
	SNode *tmp = first;
	for(int i = 0; i < size; i++){
		cout << tmp << "->";
		tmp = tmp->next;
	}
	cout << endl;
}

void SLL::priorityInsert(string s, int p) {
	if(p == 1){
		addAtFront(s,p);
	}else if(p == 2){
		addAtP2(s,p);
	}else{
		push(s,p);
	}
}

void SLL::push(string s, int p) {
	if(size==0){
		addFirst(s,p);
	}else{
		SNode *newNode = new SNode(s,p);
		last->next = newNode;
		last = newNode;
		size++;
	}
}

void SLL::addAtFront(string s, int p) {
	if(size==0){
		addFirst(s,p);
	}else{
		SNode *newNode = new SNode(s,p);
		newNode->next = first;
		first = newNode;
		size++;
	}
}

void SLL::addFirst(string s, int p) {
	SNode *newNode = new SNode(s,p);
	first = newNode;
	last = newNode;
	size++;
}

void SLL::addAtP2(string s, int p) {
	SNode *newNode = new SNode(s,p);
	if(size==0){
		addFirst(s,p);
		p2 = newNode;
	}
	else{
		newNode->next = p2->next;
		p2->next = newNode;
		size++;
	}
}

int SLL::removeAll(string w) {
	int numTimes = 0;
	SNode *tmp = first;
	for (int i = 0; i < size; i++){
		if(tmp->word == w){
			numTimes++;
		}
		tmp = tmp->next;
	}
	SNode *tmp1 = first;
	SNode *tmp2 = first->next;
	while(tmp2 != NULL){
		if(tmp2->word == w){
			if(tmp2 == last){
				pop();
				tmp2 == NULL;
			}
			else{
				tmp1->next = tmp2->next;
				tmp2 = tmp1->next;
				size--;
			}
		}else{
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}
	}
	if(first->word == w){
		last->next = first;
		first = first->next;
		delete last->next;
		last->next = NULL;
		size--;
	}
	return numTimes;
}

string SLL::pop() {
	SNode *tmp = first;
	for(int i = 0; i < size-1; i++){
		tmp = tmp->next;
	}
	string ret = last->word;
	delete last;
	last = tmp;
	size--;
	return ret;
}
