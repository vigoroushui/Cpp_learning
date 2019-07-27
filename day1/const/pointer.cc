#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int number=10;
    int number2=20;
    const int *p=&number;
    cout<<*p<<endl;
    p=&number2;
    cout<<*p<<endl;
    return 0;
}

