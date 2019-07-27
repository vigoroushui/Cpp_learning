#include <iostream>
using std::cout;
using std::endl;
namespace xyh
{
void Const()
{
    int number=1;
    int number2=2;
    const int *pa=&number;
    cout<<"before pa:"<<*pa<<endl;
    pa=&number2;
    cout<<"after pa:"<<*pa<<endl;
    int * const pb=&number;
    cout<<"before pb:"<<*pb<<endl;
    *pb=number2;
    cout<<"after pb:"<<*pb<<endl;
}
}// end of namespace xyh;
int main()
{
    xyh::Const();
    return 0;
}

