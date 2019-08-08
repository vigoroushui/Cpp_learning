#include <iostream>
#include <functional>
using std::cout;
using std::endl;

void display()
{
    cout<<"display()"<<endl;
}
void print()
{
    cout<<"print()"<<endl;
}

typedef void(*Function)();//函数类型
//定义一个自定义类型的函数指针：可以如此理解typedef void(*)() Function;但写法不对
class Example
{
public:
    Example()=default;
    void display()
    {
        cout<<"Example::display()"<<endl;
    }

    int add(int x,int y)
    {
        return x+y;
    }
    int _data=10;
};

int test0(void)
{
    void (*f)();
    f=display;
    f();
    f=print;
    f();
    return 0;
}

void test1(void)
{
    //f成为回调函数
    Function f=display;//注册回调函数
    f();//执行回调函数
    f=print;
    f();
}

void test2(void)
{
    //函数类型的容器，function是类模板
    std::function<void()> f=display;
    f();
    Example e;
    //bind是函数模板，其返回值是函数对象
    f=std::bind(&Example::display,e);
    f();
}

int add(int x,int y)
{
    cout<<"x="<<x<<endl
        <<"y="<<y<<endl;
    return x+y;
}

void test3(void)
{
    //int (*f)();如何定义auto所指代的int型函数指针？😭
    auto f =std::bind(add,1,2);
    cout<<"f():"<<endl<<f()<<endl;
    cout<<"f(2,3,4):"<<endl<<f(2,3,4)<<endl;//无效参数
    //占位符
    using namespace std::placeholders;
    auto f2=std::bind(add,1,_1);
    cout<<"f2(100):"<<f2(100)<<endl;
    auto f3=std::bind(add,_2,100);
    cout<<"f3(100):"<<f3(100,200)<<endl;
    Example e;
    //对于成员函数而言，绑定时, this指针所在的位置可以传递地址，也可以传递对象本身
	//
	//如果使用地址传递，当函数被调用时，要确保对象生命周期还存在
	//如果对象的生命周期已经结束，再调用函数时有可能会出问题
    auto f4=std::bind(&Example::add,e,_1,_2);
    cout << "f4(11, 12):" << f4(11, 12) << endl;
    //cout << "e._data = " << e._data << endl;
    auto f5 = std::bind(&Example::add, &e, 10, 20);
	cout << "f5():" << f5() << endl;
    //cout << "e._data = " << e._data << endl;
    auto f6 = std::bind(&Example::_data,&e);
	cout << "f6():" << f6() << endl;
}

void func(int x1,int x2,int x3,int &x4)
{
    cout<<"("<<x1
        <<","<<x2
        <<","<<x3
        <<","<<x4
        <<")"<<endl;
}

void test4()
{
    using namespace std::placeholders;
    int a=10;
    //std::ref 引用的包装器
	//
	//占位符本身所在的位置代表形参对应的位置,
	//占位符的数字代表的是实参的位置
    auto f=std::bind(func,_3,_4,a,std::ref(a));
    a=30;
    f(11,2,3,4);
}
int main()
{
    //test0();
    //test1();
    //test2();
    //test3();
    test4();
    return 0;
}