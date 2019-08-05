#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class SingletonTemplate
{
public:
    template <typename... Args>
    static T *getInstance(Args... args)
    {
        if(nullptr==_pInstance)
        {
            _pInstance=new T(args...);
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
    SingletonTemplate();
    ~SingletonTemplate();
private:
    static T *_pInstance;
};
template<typename T>
T *SingletonTemplate<T>::_pInstance=nullptr;
 
class Point
{
public:
    Point(int ix,int iy)
    : _ix(ix)
    , _iy(iy)
    {}
private:
    int _ix;
    int _iy;
};
class Computer
{
public:
    Computer(const char *brand,float price)
    : _brand(new char[strlen(brand)+1]())
    , _price(price)
    {
        strcpy(_brand,brand);
    }
    ~Computer()
    {
        if(_brand)
            delete []_brand;
        _brand=nullptr;
    }
private:
    char *_brand;
    float _price;
};  

int main(void)
{
    Computer *p1=SingletonTemplate<Computer>::getInstance("Xiaomi", 6666);
    Computer *p2=SingletonTemplate<Computer>::getInstance("Xiaomi", 6666);
    Point *p3=SingletonTemplate<Point>::getInstance(1, 2);
    Point *p4=SingletonTemplate<Point>::getInstance(1, 2); 
    cout<<"p1="<<p1<<endl
        <<"p2="<<p2<<endl
        <<"p3="<<p3<<endl
        <<"p4="<<p4<<endl;    
    return 0;
}