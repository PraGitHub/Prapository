#include <iostream>

using namespace std;

class A;
class B;

class A{
    string name;
    B* b;
    public:
    A(){
        name = "Class A";
        b = new B();
    }
    void print(){
        cout<<name.c_str()<<endl;
        b.print();
    }
};

class B{
    string name;
    A* a;
    B(){
        name = "Class B"<<endl;
        a = new A();
    }
    void print(){
        cout<<name.c_str()<<endl;
        a.print();
    }
}

int main()
{
    A* pA = new A();
    B* pB = new B();
    
    cout<<"Calling A's print "<<endl;
    pA->print();
    
    cout<<"Calling A's print "<<endl;
    pB.print();
    
    return 0;
}
