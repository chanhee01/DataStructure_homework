// 12191824_조찬희_자료구조론 과제
#pragma once
#include "NodeList.h"

class NodeSequence : public NodeList {
public:
	NodeSequence() : NodeList() {}
	~NodeSequence() {}
	Node* atIndex(int i) const;
	int indexOf(Node* p) const;
	int at(int i) const;
	void erase(int i);
	void insert(int i, int e);
	void set(int i, int e);
};

Node* NodeSequence::atIndex(int i) const
{
	Node* p = begin();
	for (int j = 0; j < i; j++)
		p = p->getNext();
	return p;
}

int NodeSequence::indexOf(Node* p) const {
	Node* u = header->getNext();
	for (int i = 0; i < n; i++) {
		if (u == p)
			return i;
		u = u->getNext();
	}
}

int NodeSequence::at(int i) const
{
	Node* p = begin();
	for (int j = 0; j < i; j++)
	{
		p = p->getNext();
	}
	return p->getElem();
}

void NodeSequence::erase(int i) {
	NodeList::erase(atIndex(i));
}

void NodeSequence::insert(int i, int e) {
	NodeList::insert(atIndex(i), e);
}

void NodeSequence::set(int i, int e) {
	Node* p = begin();
	for (int j = 0; j < i; j++)
	{
		p = p->getNext();
	}
	p->setElem(e);
	p->getElem();
}
