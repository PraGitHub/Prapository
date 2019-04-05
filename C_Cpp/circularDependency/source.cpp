#include <iostream>

using namespace std;

class a{
    b* mB;
    string id;
    a(){
        mB = new b();
        id = "objectOfA";
    }
    public:
    void print(){
        cour<<"class a :: print :: id = "<<id<<" ; mB->id = "<<mB->getId()<<endl;
    }
    string getId(){
        return id;
    }
};

class b{
    a* mA;
    string id;
    b(){
        mA = new a();
        id = "objectOfB";
    }
    public:
    void print(){
        cour<<"class b :: print :: id = "<<id<<" ; mA->id = "<<mA->getId()<<endl;
    }
    string getId(){
        return id;
    }
};

int main()
{
    a A;
    b B;
    A.print();
    B.print();
}