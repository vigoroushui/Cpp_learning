#include <iostream>
using std::cout;
using std::endl;

int add(int x, int y)
{
    return x+y;
}
int add(int x,int y,int z)
{
    return x+y+z;
}
int add(float x,int y)
{
    return x+y;
}
int main()
{
    int a=1,b=2,c=3;
    cout<<"a+b="<<add(a,b)<<endl;
    cout<<"a+b+c="<<add(a,b,c)<<endl;
    return 0;
}

