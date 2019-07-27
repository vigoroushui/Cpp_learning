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
    cout<<"xyh::number"<<xyh::number<<endl;
    cout<<"globalNumber="<<::number<<endl;
}
}//end of namespace xyh;

int main()
{
    xyh::display(1011);
    return 0;
}

