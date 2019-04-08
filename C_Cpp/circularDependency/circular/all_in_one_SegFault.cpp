#include <iostream>
using namespace std;

/*
this approach leads to run time error => Segmentation fault
*/

class A;
class B;

class A{
    string name;
    B* b;
    public:
    A();
    void print();
    
};
class B{
    string name;
    A* a;
    public:
    B();
    void print();
};
A :: A(){
        name = "Class A";
        b = new B();
    }
    
void A :: print(){
        cout<<name.c_str()<<endl;
        b->print();
    }
 B :: B(){
        name = "Class B";
        a = new A();
    }
void B :: print(){
        cout<<name.c_str()<<endl;
        a->print();
    }
int main()
{
    A* pA = new A();
    B* pB = new B();
    
    cout<<"Calling A's print "<<endl;
    pA->print();
    
    cout<<"Calling A's print "<<endl;
    pB->print();
    
    return 0;
}
