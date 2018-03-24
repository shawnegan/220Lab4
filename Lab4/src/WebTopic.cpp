/*
 * WebTopic.cpp
 *
 *  Created on: Mar 23, 2018
 *      Author: shawnegan
 */

#include "SLL.hpp"
#include "SNode.hpp"
#include "WebTopic.hpp"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <cctype>
using namespace std;

WebTopic::WebTopic(string filename) {
	file = filename;
	wordlist = new SLL();
	currpriority = 3;
}
void WebTopic::getPriority(string line) {
	cout << endl;
	cout << line << endl;
	if (line.compare(0,5,"title") == 0 || line.compare(0,2,"h1")==0 || line.compare(0,2, "h2")==0) {
		currpriority = 1;
	}
	else if (line.compare(0,2,"h3") == 0 ||line.compare(0,2,"h4") == 0||line.compare(0,2,"h5") == 0||line.compare(0,2,"h6") == 0) {
		currpriority = 2;
	}
	else {
		currpriority = 3;
	}
	cout << "Curr Priority: " << currpriority << endl;
 }
void WebTopic::printPage() {
	//TODO : fix (p2 at end)
	SNode *tmp = wordlist->first;
	for(int i = 0; i < wordlist->size; i++){
		if(i == 0){
			cout << "Priority 1:" << endl;
		}
		if(tmp == wordlist->p2){
			cout << endl;
			cout << "Priority 2:" << endl;
		}
		cout << tmp->word << ": " << tmp->priority;
		if(tmp->priority == 2 && tmp->next->priority == 3){
			cout << endl;
			cout << "Priority 3:" << endl;
		}
		tmp = tmp->next;
	}
}
void WebTopic::readFile() {
	ifstream infile(file.c_str(),ios::in);     // open file
	string line = "";
	char c;
	while (infile.get(c)) {
		if (c == '<') {
			if (!line.empty()) {
				cout << "Line outside of tag: "<<endl;
				cout << line << endl << endl;
				parseString(line);
				line = "";
			}
		}
		else if (c == '>') {
			cout << "Line inside of tag: "<<endl;
			cout << line << endl << endl;
			getPriority(line);
			line = "";
		}
		else {
			line += c;
		}
	}
	cout <<"*****************************************" << endl;
	cout << "BEFORE REMOVING STOP WORDS" << endl;
	printPage();
	cout << endl;
	removeStopWords();
	cout <<"*****************************************" << endl;
	cout << "AFTER REMOVING STOP WORDS" << endl;
	printPage();
	cout << endl;
	infile.close();
}
string WebTopic::stripSpace(string s) {
	unsigned int i = 0;
	while (i < s.length()) {
		if (!isalpha(s[i])) {
			s.erase(i);
		}
		i++;
	}
	return s;
}



void WebTopic::parseString(string line) {
	char *l=const_cast<char *>(line.c_str());
	char *token = strtok(l, " ");
	while (token != NULL) {
		string s = stripSpace(token);
		if (s != "") {
			wordlist->priorityInsert(s,currpriority);
		}
		token = strtok(NULL, " ");
	}
}

void WebTopic::removeStopWords(){
	for (int i = 0; i < swlen; i++){
		wordlist->removeAll(stopwords[i]);
	}
}
