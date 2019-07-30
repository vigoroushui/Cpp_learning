/**********************************************************
 * Author        : Vigoroushui
 * Email         : vigoroushui@gmail.com
 * Last modified : 2019-07-30 20:12:32
 * Filename      : Singleton1.cc
 * Description   : 
 * *******************************************************/
#include <iostream>
using std::cout;
using std::endl;
//嵌套类+静态对象
class Singleton
{
    class AutoRelease;
public:
    static Singleton * getInstance()
    {
        if(nullptr==_pInstance)
            _pInstance=new Singleton();
        return _pInstance;
    }
private:
    Singleton(){    cout<<"Singleton()"<<endl;}
    ~Singleton(){   cout<<"~Singleton()"<<endl;}
private:
    static Singleton *_pInstance;
    static AutoRelease _auto;
};
class Singleton::AutoRelease{
public:
    AutoRelease(){  cout<<"AutoRelease()"<<endl;}
    ~AutoRelease()
    {
        cout<<"~AutoRelease()"<<endl;
        if(_pInstance)
            delete _pInstance;
        _pInstance=nullptr;
    }
};
Singleton *Singleton::_pInstance=nullptr;
Singleton::AutoRelease Singleton::_auto;

int main(void)
{
    Singleton *p1=Singleton::getInstance();
    Singleton *p2=Singleton::getInstance();
    cout<<"p1="<<p1<<endl
        <<"p2="<<p2<<endl;
    return 0;
}
