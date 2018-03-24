/*
 * SNode.cpp
 *
 *  Created on: Mar 23, 2018
 *      Author: shawnegan
 */

#include "SNode.hpp"
using namespace std;

SNode::SNode(string w, int p) {
	word = w;
	priority = p;
	next = NULL;

}

SNode::~SNode() {
	if(next != NULL){
		cout << "Deleting may cause memory leak!" << endl;
	}
}

void SNode::printNode() {
	cout << word << endl;
}
