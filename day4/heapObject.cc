#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Student
{
public:
    Student(int id,const char *name)
    :_id(id)
    ,_name(new char[strlen(name)+1]())
    {
        strcpy(_name,name);
    }
    void *operator new(size_t sz)
    {
        void* ret=malloc(sz);
        return ret;
    }
    void operator delete(void* p)
    {
        free(p);
    }
    void destroy();
    void print();
private:
    ~Student()
    {
        cout<<"~Student()"<<endl;
        if(_name)
        {
            delete[]_name;
            _name=nullptr;
        }
    }
    int _id;
    char* _name;
};
void  Student::destroy()
{
    if(this)
        delete this;
    cout<<"destroy()"<<endl;
}
void Student::print()
{
    cout<<"id="<<_id<<endl;
    cout<<"name="<<_name<<endl;
}
int main()
{
    Student* pstu=new Student(220,"vigoroushui");
    pstu->print();
    pstu->destroy();
    return 0;
}

