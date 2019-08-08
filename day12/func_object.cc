#include <iostream>
#include <functional>
#include <string>
using std::cout;
using std::endl;
using std::plus;
using std::string;

int main()
{
    plus<int> intAdd;
    int sum=intAdd(20,30);
    cout<<"sum="<<sum<<endl;
    plus<string> stringAdd;
    string str=stringAdd("test20","20");
    cout<<"str="<<str<<endl;
    std::minus<int> intMinus;
    int minus=intMinus(30,1);
    cout<<"minus="<<minus<<endl;
}