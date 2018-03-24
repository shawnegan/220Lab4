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
}

void SLL::printSLL() {
	SNode *tmp = first;
	for(int i = 0; i < size; i++){
		cout << tmp->word << "->";
		tmp = tmp->next;
	}
	cout << endl;
}

void SLL::priorityInsert(string s, int p) {
	if(p == 1){
		addAtFront(s,p);
	}else if(p == 2){
		if(p2 == NULL){
			if(size == 0){
				addFirst(s,p);
			}else{
				if(first->priority == 3){
					addAtFront(s,p);
				}else{
					SNode *tmp = first;
					SNode *newNode = new SNode(s,p);
					while(p2 == NULL){
						if(tmp == last){
							push(s,p);
						}else{
							if(tmp->next->priority == 3){
								newNode->next = tmp->next;
								tmp->next = newNode;
								p2 = newNode;
								size++;
							}
						}
						tmp = tmp->next;
					}
				}
			}
		}else{
			addAtP2(s,p);
		}
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
	if(p==2){
		p2 = last;
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
	if(p==2){
		p2 = first;
	}
}

void SLL::addFirst(string s, int p) {
	SNode *newNode = new SNode(s,p);
	first = newNode;
	last = newNode;
	size++;
	if(p==2){
		p2 = newNode;
	}
}

void SLL::addAtP2(string s, int p) {
	SNode *newNode = new SNode(s,p);
	if(p2 == last){
		p2->next = newNode;
		p2 = newNode;
		size++;
		last = p2;
	}else{
		newNode->next = p2->next;
		p2->next = newNode;
		p2 = newNode;
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
				tmp2 = NULL;
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
