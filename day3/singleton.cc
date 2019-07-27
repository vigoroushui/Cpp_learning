#include <iostream>
using std::cout;
using std::endl;
class Singleton
{
public:
    static Singleton* getInstance()
    {
        if(nullptr==_pInstance)
        {
            _pInstance=new Singleton();
        }
        return _pInstance;
    }
    static void destory()
    {
        if(_pInstance)
        {
            delete _pInstance;
        }
    }
private:
    Singleton(){cout<<"这是私有化的构造函数"<<endl;}
    ~Singleton(){cout<<"这是私有化的析构函数"<<endl;}
private:
    static Singleton* _pInstance;
};
Singleton *Singleton::_pInstance=nullptr;

int main(void)
{
    Singleton *p=Singleton::getInstance();
    cout<<"p="<<p<<endl;
    Singleton::destory();
}

