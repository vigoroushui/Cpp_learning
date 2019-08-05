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

