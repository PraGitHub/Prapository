#include<iostream>
using namespace std;

class A; // not required
class B;

class A{
	string name;
	B* b;
public:
	A();
	void set(B* pB);
	string get();
	void print();

};
class B{
	string name;
	A* a;
public:
	B();
	void set(A* pA);
	string get();
	void print();
};

A::A(){
	name = "Class A";
}

void A::set(B* pB){
	b = pB;
}

void A::print(){
	cout << name.c_str() << endl;
	cout << b->get().c_str() << endl;
}

string A::get(){
	return name;
}

B::B(){
	name = "Class B";
	a = new A();
}
void B::set(A* pA){
	a = pA;
}

void B::print(){
	cout << name.c_str() << endl;
	cout << a->get().c_str() << endl;
}

string B::get(){
	return name;
}

int main()
{
	A* pA = new A();
	B* pB = new B();

	pA->set(pB);
	pB->set(pA);

	cout << "Calling A's print " << endl;
	pA->print();

	cout << "Calling B's print " << endl;
	pB->print();

	return 0;
}
