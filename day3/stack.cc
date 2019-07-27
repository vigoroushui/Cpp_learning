#include <iostream>
using std::cout;
using std::endl;
//若0本身是栈顶的元素，
//那它作为top()函数中空栈的返回标志就不太恰当
class Stack
{
public:
    Stack()
    {
        length=0;
    }
    void push(int);
    void pop();
    int top();
    bool empty();
    bool full();
private:
    int stackData[10];
    int length;
};

void Stack::push(int data)
{
    if(length>=10)
    {
        cout<<"error:stack overflow"<<endl;
    }else{
        stackData[length++]=data;
    }
}
void Stack::pop()
{
    if(length<1)
    {
        cout<<"error:stack is empty"<<endl;
    }else{
        length--;
    }
}
int Stack::top()
{
    if(length!=0)
    {
        return stackData[length-1];
    }else{
        cout<<"error:stack is empty"<<endl;
        return 0;
    }
}
bool Stack::empty()
{
    if(0==length){
        return 1;
    }else{
        return 0;
    }
}
bool Stack::full()
{
    if(10==length)
    {
        return 1;
    }else{
        return 0;
    }
}
int main()
{
    Stack st;
    st.push(10);
    st.push(12);
    st.push(14);
    int topElem;
    topElem=st.top();
    cout<<"topElem="<<topElem<<endl;
    st.pop();
    topElem=st.top();
    cout<<"topElem="<<topElem<<endl;    
    return 0;
}

