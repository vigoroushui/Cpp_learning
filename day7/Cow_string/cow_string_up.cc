/**********************************************************
 * Author        : Vigoroushui
 * Email         : vigoroushui@gmail.com
 * Last modified : 2019-07-31 14:52
 * Filename      : cow_string_up.cc
 * Description   : 
 * *******************************************************/
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class CowString
{
    class CharProxy
    {
    public:
        CharProxy(CowString &self,size_t idx)
        : _self(self)
        , _idx(idx)
        {}
        //执行写操作
        char & operator=(const char &ch);
        //执行读操作
        operator char()
        {
            return _self._pstr[_idx];
        }
    private:
        CowString &_self;
        size_t _idx;
    };
public:
    CowString();
    CowString(const char *pstr);
    CowString(const CowString &rhs);
    CowString &operator=(const CowString &rhs);
    ~CowString();
    const char *c_str() const {   return _pstr;}
    size_t size() const {   return strlen(_pstr);}
    int refcount() const {  return *(int*)(_pstr-4);}
    CharProxy operator[](size_t idx);
    const char operator[](size_t idx) const {   return _pstr[idx];}
    friend std::ostream &operator<<(std::ostream &os,const CowString &rhs);
private:
    void initRefcount()
    {   *(int*)(_pstr-4)=1;}
    void increaseRefcount()
    {   ++*(int*)(_pstr-4);}
    void decreaseRefcount()
    {   --*(int*)(_pstr-4);}
    void release()
    {
        decreaseRefcount();
        if(0==refcount())
        {
            delete[] (_pstr-4);
            cout<<"delete heap data"<<endl;
        }
    }
private:
    char *_pstr;
};
CowString::CowString()
: _pstr(new char[4+1]()+4)
{
    initRefcount();
    cout<<"CowString()"<<endl;
}
CowString::CowString(const char *pstr)
: _pstr(new char[strlen(pstr)+5]()+4)
{
    initRefcount();
    strcpy(_pstr,pstr);
}
CowString::CowString(const CowString &rhs)
: _pstr(rhs._pstr)
{
    increaseRefcount();
}
CowString & CowString::operator=(const CowString &rhs)
{
    if(this!=&rhs)
    {
        release();
        _pstr=rhs._pstr;
        increaseRefcount();
    }
    return *this;
}
CowString::~CowString()
{
    release();
}
std::ostream &operator<<(std::ostream &os,const CowString &rhs)
{
    os<<rhs._pstr;
    return os;
}
CowString::CharProxy CowString::operator[](size_t idx)
{
    return CharProxy(*this,idx);
}

char & CowString::CharProxy::operator=(const char &ch)
{
    if(_idx<_self.size())
    {
        if(_self.refcount()>1)
        {
            _self.decreaseRefcount();
            char *ptmp=new char[_self.size()+5]()+4;
            strcpy(ptmp,_self._pstr);
            _self._pstr=ptmp;
            _self.initRefcount();
        }
        _self._pstr[_idx]=ch;
        return _self._pstr[_idx];
    }else{
        static char nullchar='\0';
        return nullchar;
    }
}
int main(void)
{
    CowString s1 = "hello,world";
    CowString s2 = s1; 
    CowString s3 = "shenzhen";
    cout << "s3 = " << s3 << endl;
    s3 = s1; 
    cout << "执行赋值操作之后:" << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address is %p\n", s1.c_str());
    printf("s2's address is %p\n", s2.c_str());
    printf("s3's address is %p\n", s3.c_str());
    cout << "s1's refcount = " << s1.refcount() << endl;
    cout << "s2's refcount = " << s2.refcount() << endl;
    cout << "s3's refcount = " << s3.refcount() << endl;                                 
    cout << "\n 修改共享字符串的内容之后:" << endl;
    s3[0] = 'X';
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address is %p\n", s1.c_str());
    printf("s2's address is %p\n", s2.c_str());
    printf("s3's address is %p\n", s3.c_str());
    cout << "s1's refcount = " << s1.refcount() << endl;
    cout << "s2's refcount = " << s2.refcount() << endl;
    cout << "s3's refcount = " << s3.refcount() << endl;
    cout << "\n 执行读操作之后:" << endl;
    cout << "s1[0] = " << s1[0] << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address is %p\n", s1.c_str());
    printf("s2's address is %p\n", s2.c_str());
    printf("s3's address is %p\n", s3.c_str());
    cout << "s1's refcount = " << s1.refcount() << endl;
    cout << "s2's refcount = " << s2.refcount() << endl;
    cout << "s3's refcount = " << s3.refcount() << endl;
    return 0;
}                             
