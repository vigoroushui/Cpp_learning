#include "String.h"
#include <string.h>
using std::cout;
using std::endl;

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

}

