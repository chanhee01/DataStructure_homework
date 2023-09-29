// 12191824_조찬희_자료구조론 과제
#include <iostream>
using namespace std;

class Node {
private:
	int elem;
	Node* prev;
	Node* next;
public:
	Node();
	int getElem() { if (elem != NULL) return elem; }
	void setElem(int e) { elem = e; }
	Node* getNext() { if (next != NULL) return next; }
	void setNext(Node* n) { next = n; }
	Node* getPrev() { if (prev != NULL) return prev; }
	void setPrev(Node* p) { prev = p; }
};

Node::Node() : elem(0), next(NULL), prev(NULL) {};