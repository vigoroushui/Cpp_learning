#include <iostream>
using std::cout;
using std::endl;

int number=220;
namespace xyh
{
int number=315;
void display(int number)
{
    cout<<"number="<<number<<endl;
    cout<<"xyh::number="<<xyh::number<<endl;
    cout<<"globalNumber="<<::number<<endl;
}
}//end of namespace xyh;

namespace lak
{
int a=10;
void print()
{
    xyh::display(3);
}
namespace xyh
{
int b=5;
int display()
{
    cout<<"lak::xyh::display()"<<endl;
    return 0;
}
void display2(int b)
{
    cout<<"lak::xyh::b="<<b<<endl;
}
}//end of namespace xyh;
void display()
{
    cout<<"lak::display()"<<endl;
}
}//end of namespace lak;

int main()
{
    xyh::display(1011);
    lak::print();
    lak::display();
    lak::xyh::display();
    lak::xyh::display2(5);
    return 0;
}

