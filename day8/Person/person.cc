#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Person
{
public:
    Person()
    : _name()
    , _age(0)
    {}   
    Person(const char* name, int age)
    : _name(new char[strlen(name)+1]())
    , _age(age)
    {
        strcpy(_name,name);
    }
    void display()
    {
        cout<<"name: "<<_name<<endl
            <<"age: "<<_age<<endl;
    }
    ~Person()
    {
        if(_name)
            delete []_name;
        _name=NULL;
    }
private:
    char* _name;
    int _age;
};
class Emplyee
:public Person
{
public:
    Emplyee(const char * name,int age,const char *department,float salary)
    : Person(name,age)
    , _department(new char[strlen(department)+1]())
    , _salary(salary)
    {
        strcpy(_department,department);
    }
    void display()
    {
        Person::display();
        cout<<"department: "<<_department<<endl
            <<"salary: "<<_salary<<endl
            <<"--------------------------------"<<endl;
    }
    float getSalary() const {   return _salary;}
    ~Emplyee()
    {
        if(_department)
            delete [] _department;
        _department=NULL;
    }
private:
    char * _department;
    float _salary;
};

int main(void)
{
    Emplyee E1("zhangsan",21,"product",10000.5);
    Emplyee E2("lisi",22,"front-end develop",12000.5);
    Emplyee E3("wangwu",23,"back-end develop",14500.5);
    E1.display();
    E2.display();
    E3.display();
    float salaryAve=(E1.getSalary()+E2.getSalary()+E3.getSalary())/3;
    cout<<"The average of salary: "<<salaryAve<<endl;
}
