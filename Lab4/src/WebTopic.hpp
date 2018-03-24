/*
 * WebTopic.hpp
 *
 *  Created on: Mar 23, 2018
 *      Author: shawnegan
 */

#ifndef WEBTOPIC_HPP_
#define WEBTOPIC_HPP_

#include "SNode.hpp"
#include "SLL.hpp"
#include <stdlib.h>
using namespace std;

class WebTopic {
	int currpriority;
	SLL *wordlist;
	string file;
	string stopwords[50]={"a",
			"along",
			"although",
			"am",
			"among",
			"and",
			"are",
			"as",
			"at",
			"be",
			"because",
			"between",
			"can",
			"do",
			"dont",
			"either",
			"for",
			"got",
			"has",
			"have",
			"havent",
			"he",
			"i",
			"in",
			"is",
			"isnt",
			"it",
			"more",
			"much",
			"neither",
			"no",
			"none",
			"nor",
			"not",
			"of",
			"one",
			"or",
			"that",
			"the",
			"they",
			"this",
			"though",
			"was",
			"when",
			"while",
			"why",
			"with",
			"without",
			"you",
			"your"
	};
int swlen = 50;
public:
	WebTopic(string filename);
	void readFile();
	void parseString(string line);
	string stripSpace(string s);
	void getPriority(string line);
	void printPage();
	void removeStopWords();
};

#endif /* WEBTOPIC_HPP_ */
