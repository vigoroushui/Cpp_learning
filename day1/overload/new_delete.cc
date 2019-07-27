#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

void test0()
{
    int *pointer1=(int *)malloc(sizeof(int));
    *pointer1=10;
    int *pointer2=(int *)malloc(10*sizeof(int));
    pointer2[0]=2;
    pointer2[1]=3;
    pointer2[3]=4;
    cout<<pointer2[0]<<"  "<<pointer2[1]<<"  "<<pointer2[3]<<endl;
    free(pointer1);
    free(pointer2);    
}

void test1()
{
    int *pointer1=new int(3);
    cout<<"*pointer1="<<*pointer1<<endl;
    int *pointer2=new int[4];
    cout<<pointer2[0]<<"  "<<pointer2[1]<<"  "<<pointer2[3]<<endl;
    int *pointer3=new int[4]();
    cout<<pointer3[0]<<"  "<<pointer3[1]<<"  "<<pointer3[3]<<endl;
    delete pointer1;
    delete [] pointer2;
    delete [] pointer3;
}
int main()
{
    //test0();
    test1();
    return 0;
}

