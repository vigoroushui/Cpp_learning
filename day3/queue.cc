#include <iostream>
using std::cout;
using std::endl;
class Queue
{
public:
    Queue(int size=10)
    :_size(size)
    ,_front(0)
    ,_rear(0)
    ,_data(new int[_size]())
    {
    }
    ~Queue()
    {
        if(_data)
        {
            delete[] _data;
        }
    }
    void push(int number)
    {
        if(!full())
        {
            _data[_rear++]=number;
            _rear%=_size;
        }else{
            cout<<"queue is full,cannot push any more data!"<<endl;
        }
    }
    void pop()
    {
        if(!empty())
        {
            ++_front;
            _front%=_size;
        }else{
            cout<<"queue is empty,cannot pop any more data!"<<endl;
        }
    }
    int front()
    {
        return _data[_front];
    }
    int back()
    {
        return _data[_rear-1+_size]%_size;
    }
    bool empty() const
    {
        return _front==_rear;
    }
    bool full() const
    {
        return _front==(_rear+1)%_size;
    }
private:
    int _size;
    int _front;
    int _rear;
    int *_data;
};

int main()
{
    Queue qt(10);
    qt.push(10);
    qt.push(12);
    qt.push(14);
    int frontElem,backElem;
    frontElem=qt.front();
    backElem=qt.back();
    cout<<"frontElem="<<frontElem<<endl;
    cout<<"backElem="<<backElem<<endl;
    qt.pop();
    frontElem=qt.front();
    backElem=qt.back();
    cout<<"frontElem="<<frontElem<<endl;
    cout<<"backElem="<<backElem<<endl;
    return 0;
}

