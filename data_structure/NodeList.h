// 12191824_조찬희_자료구조론 과제
#include "Node.h"

class NodeList : public Node {
protected:
	int n;
	Node* header;
	Node* trailer;
public:
	NodeList();
	~NodeList();
	int size() const { return n; }
	bool empty() const { return(n == 0); }
	Node* begin() const { return (header->getNext()); }
	Node* end() const { return (trailer); }
	void insert(Node* p, int e);
	void erase(Node* p);
};

NodeList::NodeList() {
	n = 0;
	header = new Node;
	trailer = new Node;
	header->setNext(trailer);
	trailer->setPrev(header);
}

NodeList::~NodeList() {
	while (!empty()) erase(begin());
	delete header;
	delete trailer;
}

void NodeList::insert(Node* p, int e) {
	Node* u = new Node;
	u->setElem(e);
	u->setNext(p);
	u->setPrev(p->getPrev());
	(p->getPrev())->setNext(u);
	p->setPrev(u);
	n++;
}

void NodeList::erase(Node* p) {
	Node* u = new Node;
	Node* w = new Node;
	p->setPrev(u);
	p->setNext(w);
	u->setNext(w);
	w->setPrev(u);
	n--;
}