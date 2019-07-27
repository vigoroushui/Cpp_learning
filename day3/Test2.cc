#include"MutexLock_Condition.h"
#include <pthread.h>
using std::cout;
using std::endl;

int ticket=200;
bool flag=true;
MutexLock gmutex;
Condition gcondition(gmutex);

void *windows1(void *arg)
{
    int cnt=20;
    //flag==true,sale tickets
    while(cnt--)
    {
        //使用MutexLockGuard对象，可以保证不会发生死锁   
        MutexLockGuard autoLock(gmutex);//RAII
        //gmutex.lock();
        //if(!flag)//flag==false
        while(!flag)//使用while是为了防止异常唤醒
        {
            gcondition.wait();//出现异常（虚假）唤醒
        }
        --ticket;
        cout<<"windows1"<<pthread_self()
            <<": left tickets="<<ticket<<endl;
        if(flag)
            flag=false;
        gcondition.notify();
        //gmutex.unlock();
    }
    return nullptr;
}

void *windows2(void *arg)
{
    int cnt=20;
    while(cnt--)
    {
        //flag==false,sale tickets
        //gmutex.lock();
        MutexLockGuard autoLock(gmutex);
        while(flag)
        {
            gcondition.wait();
        }
        cout<<"windows2"<<pthread_self()
            <<": left tickets="<<ticket<<endl;
        --ticket;
        if(!flag)
            flag=true;
        gcondition.notify();
        //...return 产生死锁
        //gmutex.unlock();
    }
    return nullptr;
}

int main(void)
{
    pthread_t pthid1,pthid2;
    pthread_create(&pthid1,NULL,windows1,NULL);
    pthread_create(&pthid2,NULL,windows2,NULL);
    pthread_join(pthid1,NULL);
    pthread_join(pthid2,NULL);
    return 0;
}

