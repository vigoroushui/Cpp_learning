#include <string.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
class Student
{
public:
    Student(int id,const char* name)
    :_id(id)
    ,_name(new char[strlen(name)+1]())
    {
        strcpy(_name,name);
    }
    ~Student()
    {
        if(_name)
        {
            delete []_name;
            _name=nullptr; 
        }
    }
    void print();
private:
    void * operator new(size_t sz)
    {
        void* ret=malloc(sz);
        return ret;
    }
    void operator delete(void* p)
    {
        free(p);
        p=NULL;
    }
private:
    int _id;
    char* _name;
};
void Student::print()
{
    cout<<"id="<<_id
        <<"name="<<_name<<endl;
}    
int main()
{
    Student s(220,"Vigoroushui");
    s.print();
    return 0;
}

