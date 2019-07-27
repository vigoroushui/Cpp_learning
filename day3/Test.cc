#include "MutexLock_Condition.h"
#include <pthread.h>
#define NUMBER 20000000
int value=0;

void* threadFunc(void *p)
{
    pthread_mutex_t* mutex;
    mutex=(pthread_mutex_t*)p;
    int i;
    for(i=0;i<NUMBER;i++)
    {
        pthread_mutex_lock(mutex);
        value+=1;
        pthread_mutex_unlock(mutex);
    }
    return NULL;
}
int main()
{
    pthread_t pthid;
    MutexLock mutex;
    pthread_create(&pthid,NULL,threadFunc,mutex.getMutex());
    int i;
    for(i=0;i<NUMBER;i++)
    {
        mutex.lock();
        value+=1;
        mutex.unlock();
    }
    pthread_join(pthid,NULL);
    cout<<"main thread,value="<<value<<endl;
    return 0;
}

