#include <iostream>
using std::cout;
using std::endl;
template <class T>
class Singleton
{
    class AutoRelease
    {
    public:
        AutoRelease();
        ~AutoRelease()
        {
            if(_pInstance)
                delete _pInstance;
        }
    };
public:
    template<class... Args>
    static T * getInstance(Args... args)
    {
        if(_pInstance==nullptr)
        {
            (void) auto;
            _pInstance=new T(args...);
        }
        return _pInstance;
    }
private:
    Singleton();
    ~Singleton();
private:
    static T *_pInstance;
    static AutoRelease _auto;
};

template<class T>
T *Singleton<T>::_pInstance=nullptr;

template<class T>
typename Singleton<T>::AutoRelease Singleton<T>::_auto;