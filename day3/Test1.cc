#include "MutexLock_Condition.h"
#include <unistd.h>
void* threadFunc(void* p)
{
    Condition *condition= (Condition *)p;
    condition->wait();
    return nullptr;
}

int main()
{
    MutexLock mutex;
    Condition condition(mutex);
    pthread_t pthid;
    pthread_create(&pthid,NULL,threadFunc,&condition);
    sleep(5);
    cout<<"It's testing"<<endl;
    condition.notify();
    pthread_join(pthid,NULL);
    return 0;
}

