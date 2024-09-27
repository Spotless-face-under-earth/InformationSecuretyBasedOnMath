#pragma once
#include <deque>
#include<iostream>
using namespace std;
class Node {
public:
	int xp; int yp;
	Node() {
		xp = 0;yp = 0;
	}
	Node(int a, int b) {
		xp = a;yp = b;
	}
	void output()
	{
		cout<< "(" << xp << "," << yp << ") ,";
	}
};
class EllipticCurve {
	int a;int b;int p;
public:
	EllipticCurve(int aa, int bb, int pp) {
		a = aa;b = bb;p = pp;
	}
	bool isOnCurve(Node p);
	Node addP(Node a, Node b);
	Node multiAddP(int n, Node p);
	int getOrdP(Node p);
	int getPNum();
	deque<Node> getP();
	int EllipticCurveAlu(int x);
};
bool isEllipticCurve(int a, int b, int p);
int getEuroFunc(int a);



