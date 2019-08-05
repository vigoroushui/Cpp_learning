
### 1. 实现一个队列的类模板
代码如下：
```cpp
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template<class T,int keySize=10>
class Queue
{
public:
    Queue()
    : _size(keySize)
    , _front(0)
    , _rear(0)
    , _data(new T[keySize]())
    {}
    ~Queue();
    bool full() const;
    bool empty() const;
    void push(const T &t);
    void pop();
    T &front() const;
    T &back() const;
private:
    int _size;
    int _front;
    int _rear;
    T *_data;
};
template<class T,int keySize>
Queue<T,keySize>::~Queue()
{
    if(_data)
        delete [] _data;
}
template<class T,int keySize>
bool Queue<T,keySize>::full() const
{
    return _front==(_rear+1)%_size;
}
template<class T,int keySize>
bool Queue<T,keySize>::empty() const
{
    return _front==_rear;
}
template<class T,int keySize>
void Queue<T,keySize>::push(const T &t)
{
    if(full())
    {
        cout<<"The Queue is full, you can't push anymore!"<<endl;
    }else{
        _data[_rear++]=t;
        _rear%=_size;
    }
}
template<class T,int keySize>
void Queue<T,keySize>::pop()
{
    if(empty())
    {
        cout<<"The Queue is empty, you can't push anymore!"<<endl;
    }else{
        ++_front;
        _front%=_size;
    }
}
template<class T,int keySize>
T &Queue<T,keySize>::front() const
{
    return _data[_front];
}
template<class T,int keySize>
T &Queue<T,keySize>::back() const
{
    return _data[(_rear-1+_size)%_size];
}    

int main()
{
    Queue<string> queue;
    cout<<"此时队列中是否为空?"<<queue.empty()<<endl;
    queue.push("aaaa");
    cout<<"此时队列中是否为空?"<<queue.empty()<<endl;
    for(int i=1;i!=10;++i)
    {
        queue.push(string(4,'a'+i));
    }
    cout<<"此时队列中是否已满？"<<queue.full()<<endl;
    cout<<"front="<<queue.front()<<endl;
    cout<<"back="<<queue.back()<<endl
        <<"------------------------------"<<endl;
    while(!queue.empty())
    {
        cout<<queue.front()<<endl;
        queue.pop();
    }
    cout<<"此时队列中是否为空?"<<queue.empty()<<endl;
}
```
### 2. 实现一个模板形式的单例类
要求对于任意类型的类经过Singleton的处理之后，都能获取一个单例对象，并且可以传递任意参数
代码如下：
```cpp
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
```
     
### 3.实现log4cpp的封装，使其可以像printf一样使用，测试用例如下:
```cpp
//coding
void test() {
	int number = 100;
	const char * pstr = "hello, log4cpp";
	LogInfo("this is an info message. number = %d, str = %s\n", number, pstr);
}
```
### 4.STL是由哪些组件构成的？它们各自具备什么样的特点？
- 容器：容器是可容纳一些数据的类模板，STL中有vector、list、deque、set/multiset、map/multimap等容器。

- 迭代器：迭代器也称游标，可以将迭代器初步理解为广义指针，迭代器和指针功能很像，迭代器是通过重载一元的”*”和”->”来从容器中间接地返回一个值。

- 适配器：Interface(接口)，对容器、迭代器和算法进行包装，但其实质还是容器、迭代器和算法，只是不依赖于具体的标准容器、迭代器和算法类型，容器适配器可以理解为容器的模板，迭代器适配器可理解为迭代器的模板，算法适配器可理解为算法的模板。

- 算法：算法通过迭代器存取容器内容。用来处理群集内的元素。它们可以出于不同的目的而搜寻、排序、修改、使用那些元素。通过迭代器的协助，我们可以只需编写一次算法，就可以将它应用于任意容器，这是因为所有的容器迭代器都提供一致的接口

- 函数对象：行为类似函数，可作为算法的某种策略（Policy），从实现的角度来看，函数对象是一种重载了Operator()的Class 或 Class Template。一般函数指针可视为狭义的函数对象。

- 配置器：负责空间配置与管理，从实现的角度来看，配置器是一个实现了动态空间配置、空间管理、空间释放的Class Template。

### 5.序列式容器都有哪些异同？
序列式容器会强调元素的次序，依次维护第一个元素、第二个元素……，直到最后一个元素，面向序列式容器的操作主要是迭代操作。序列容器以线性序列的方式存储元素。它没有对元素进行排序，元素的顺序和存储它们的顺序相同。以下有3种标准的序列容器，每种容器都具有不同的特性：

- vector<T>(向量容器)是一个长度可变的序列，用来存放 T 类型的对象。必要时，可以自动增加容量，但只能在序列的末尾高效地增加或删除元素。
- deque<T>(双向队列容器)是一个长度可变的、可以自动增长的序列，在序列的两端都不能高效地增加或删除元素。
- list<T>(链表容器)是一个长度可变的、由 T 类型对象组成的序列，它以双向链表的形式组织元素，在这个序列的任何地方都可以高效地增加或删除元素。访问容器中任意元素的速度要比前三种容器慢，这是因为 list<T> 必须从第一个元素或最后一个元素开始访问，需要沿着链表移动，直到到达想要的元素。