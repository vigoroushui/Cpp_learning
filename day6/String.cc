#include "String.h"
#include <string.h>
#include <stdio.h>
using std::cout;
using std::endl;
//默认构造函数
String::String()
{
    _pstr=new char[MAXSIZE]();
}
//构造函数：C风格的类型转换
String::String(const char *pstr)
    :_pstr(new char[strlen(pstr)+1]())
{
    strcpy(_pstr,pstr);
}
//拷贝构造函数
String::String(const String &rhs)
    :_pstr(new char[strlen(rhs._pstr)+1]())
{
    strcpy(_pstr,rhs._pstr);
}
//析构函数
String::~String()
{
    if(_pstr)
        delete [] _pstr;
    _pstr=NULL;
}
//赋值运算符的重载
String & String::operator=(const String &rhs)
{
    if(this!=&rhs)
    {
        delete [] _pstr;
        _pstr=new char[strlen(rhs._pstr)+1]();
        strcpy(_pstr,rhs._pstr);
    }
    return *this;
}
//赋值运算符的重载，C风格的类型转换
String & String::operator=(const char *pstr)
{
    _pstr=new char[strlen(pstr)+1]();
    strcpy(_pstr,pstr);
    return *this;
}
//+=运算符的重载
String & String::operator+=(const String &rhs)
{
    if(_pstr!=NULL||sizeof(_pstr)<strlen(rhs._pstr)+strlen(_pstr)+1)
    {
        char *tmp=_pstr;
        tmp=new char[strlen(rhs._pstr)+strlen(_pstr)+1](); 
        sprintf(tmp,"%s%s",_pstr,rhs._pstr);
        strcpy(_pstr,tmp);
    }else{
        strcpy(_pstr,rhs._pstr);
    }
    return *this;
}
//+=运算符的重载,C风格的类型转换
String & String::operator+=(const char *pstr)
{
    return *this+=String(pstr);
}
//下标访问运算符重载
char & String::operator[](std::size_t index)
{
    if(index<this->size())
    {
        return _pstr[index];
    }else{
        static char nullchar='\0';
        return nullchar;
    }
}

const char & String::operator[](std::size_t index) const
{
    return _pstr[index];
}

std::size_t String::size() const
{
    return strlen(_pstr);
}

const char* String::c_str() const
{
    return _pstr;
}

bool operator==(const String &lhs,const String &rhs)
{
    return !strcmp(lhs._pstr,rhs._pstr);
}

bool operator!=(const String &lhs,const String &rhs)
{
    return !(lhs==rhs);
}

bool operator<(const String &lhs,const String &rhs)
{
    return strcmp(lhs._pstr,rhs._pstr)<0;
}

bool operator>(const String &lhs,const String &rhs)
{
    return strcmp(lhs._pstr,rhs._pstr)>0;
}

bool operator<=(const String &lhs,const String &rhs)
{
    return strcmp(lhs._pstr,rhs._pstr)<=0;
}

bool operator>=(const String &lhs,const String &rhs)
{
    return strcmp(lhs._pstr,rhs._pstr)>=0;
}

std::ostream &operator<<(std::ostream &os,const String &s)
{
    os<<s._pstr;
    return os;
}

std::istream &operator>>(std::istream &is,const String &s)
{
    is>>s._pstr;
    return is;
}

String operator+(const String &s1,const String &s2)
{
    String tmp=s1;
    tmp+=s2;
    return tmp;
}
String operator+(const String &s1,const char *s2)
{
    return s1+String(s2);
}

String operator+(const char *s1,const String &s2)
{
    return String(s1)+s2;
}
int main()
{
    String s;
    String s2="c++";
    s="hello";
    cout<<"s="<<s<<endl;
    s+="world";
    cout<<"char s+="<<s<<endl;
    s+=s2;
    cout<<"String s+="<<s<<endl;
    cout<<"s[2]="<<s[2]<<endl;
    char *a=new char[20]();
    strcpy(a,s2.c_str());
    cout<<"a=s2.c_str():"<<a<<endl;
    cout<<"s+s2="<<s+s2<<endl;
    cout<<"a+s="<<a+s<<endl;
}

