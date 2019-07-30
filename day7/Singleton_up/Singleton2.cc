/**********************************************************
 * Author        : Vigoroushui
 * Email         : vigoroushui@gmail.com
 * Last modified : 2019-07-30 20:30:09
 * Filename      : Singleton2.cc
 * Description   : 
 * *******************************************************/
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton *getInstance()
    {
        if(nullptr==_pInstance)
        {
            ::atexit(destroy);
            _pInstance=new Singleton();
        }
        return _pInstance;
    }
    static void destroy()
    {
        if(_pInstance)
            delete _pInstance;
        _pInstance=nullptr;
    }
private:
    Singleton(){    cout<<"Singleton()"<<endl;}
    ~Singleton(){   cout<<"~Singleton()"<<endl;}
private:
    static Singleton *_pInstance;
};
Singleton *Singleton::_pInstance=getInstance();

int main(void)
{
    Singleton *p1=Singleton::getInstance();
    Singleton *p2=Singleton::getInstance();
    cout<<"p1="<<p1<<endl
        <<"p2="<<p2<<endl;
    return 0;
}
