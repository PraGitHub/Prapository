#include <iostream>

using namespace std;

/*
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
        b->print();
    }
};

class B{
    string name;
    A* a;
    B(){
        name = "Class B";
        a = new A();
    }
    void print(){
        cout<<name.c_str()<<endl;
        a->print();
    }
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
*/

#include <iostream>

using namespace std;

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


/*
This code will give this error => Line 22:19: error: invalid use of incomplete type ‘class B’
*/
