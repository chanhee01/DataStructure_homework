// 12191824_조찬희_자료구조론 과제
#include <iostream>
#include "NodeSequence.h"
using namespace std;

void bubbleSort2(NodeSequence& S) {
	int n = S.size();
	Node* u = S.begin();
	Node* v = S.begin()->getNext();
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n ; j++) {
			int a = u->getElem();
			int b = v->getElem();
			int tmp = 0;
			if (a > b) {
				tmp = a;
				a = b;
				b = tmp;
				u->setElem(a);
				v->setElem(b);
			}
			v = v->getNext();
			u = u->getNext();
		}
		u = S.begin();
		v = S.begin()->getNext();
	}
}

Node* linearSearch(NodeSequence& S, int k) {
	int n = S.size();
	Node* u = new Node;
	u = S.begin();
	for (int i = 0; i < n; i++) {
		if (u->getElem() == k) {
			return S.atIndex(i);
		}
		if (k == n + 1) {
			return NULL;
		}
		u = u->getNext();
	}
}

int main() {
	const int NOS = 7;
	int a[NOS] = { 6, 7, 2, 5, 1, 4, 3 };
	NodeSequence ns;
	for (int i = 0; i < NOS; i++) ns.insert(i, a[i]);
	cout << "A sequence of size = " << ns.size() << endl;
	bubbleSort2(ns);
	cout << "---- Testing index-based operations ----" << endl;
	for (int i = 0; i < NOS; i++) {
		cout << "Index = " << i << " => " << ns.at(i) << endl;
	}
	cout << "---- Testing position(pointer)-based operations ----\n";
	int k;
	Node* retPos;
	cout << "Entery searching key (-1 for exit) : ";
	cin >> k;
	while (k != -1) {
		retPos = linearSearch(ns, k);
		if (retPos == NULL) cout << "Searching key is not found! \n";
		else
			cout << "Key is at index = " << ns.indexOf(retPos) << endl;
		cout << "Entery searching key (-1 for exit) : ";
		cin >> k;
	}
	for (int i = 0; i < 7; i++) ns.erase(0);
}
