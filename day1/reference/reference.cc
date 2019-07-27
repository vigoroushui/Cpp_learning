#include <iostream>
using std::cout;
using std::endl;

void test0()
{
    int number=10;
    int &ref=number;
    cout<<"&number="<<&number<<endl;
    cout<<"&ref="<<&ref<<endl;
    cout<<"number="<<number<<endl;
    cout<<"ref="<<ref<<endl;
    ref=20;
    cout<<"number="<<number<<endl;
    cout<<"ref="<<ref<<endl;
}
//值传递，指针传递，引用传递
#if 0
#endif//注释方法

void swap(int &x,int &y)
{
    int z=x;
    x=y;
    y=z;
}

int array[5]={0,1,2,3,4};
int getNumber(int idx)
{
    return array[idx];//int型返回值，return时会进行复制
}
int &getNumber1(int idx)
{
    return array[idx];//int&型返回值，return时不会进行复制
}
#if 0
int &getNumber0()
{   
    int number=10;
    return 10;
}//不能返回一个局部变量的引用
#endif
//没内存回收策略的情况下，不要返回一个堆空间变量的引用
int &getNumber2()
{
    int *pointer=new int(1);
    cout<<"pointer="<<pointer<<endl;
    return *pointer;
}
void test1()
{
    int a=getNumber(1);
    cout<<"a="<<a<<endl;
    getNumber1(3)=220;
    cout<<"array[3]="<<array[3]<<endl;
    int &b=getNumber2();
    cout<<"b="<<b<<endl;
    cout<<"&b="<<&b<<endl;
    delete &b;
}

int main()
{
    test1();
    return 0;
}

