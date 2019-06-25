#include <iostream>
using namespace std;

int* fun1(int* x)
{
    x = x + 1;
    return x;
}

int* fun2(int* x)
{
    return x;
}

int* fun3(int& x)
{
    x = x + 1;
    return &x;
}

int* fun4(int* x)
{
    *x = *x + 1;
    return x;
}

int main() {
    int x = 1;
    int* y = nullptr;
    
    y = fun1(&x);
    cout<<"*y = "<<*y<<endl;
    
    y = fun2(&x);
    cout<<"*y = "<<*y<<endl;
    
    y = fun3(x);
    cout<<"*y = "<<*y<<endl;
    
    y = fun4(&x);
    cout<<"*y = "<<*y<<endl;
    
    return 0;
}
