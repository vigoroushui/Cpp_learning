#include <iostream>
using std::cout;
using std::endl;
class MutexLock
{
public:
    MutexLock()
    {
        cout<<"MutexLock()"<<endl;
        pthread_mutex_init(&_mutex,NULL);
    }
    ~MutexLock()
    {
        cout<<"~MutexLock()"<<endl;
        pthread_mutex_destroy(&_mutex);
    }
    void lock()
    {
        pthread_mutex_lock(&_mutex);
    }
    void unlock()
    {
        pthread_mutex_unlock(&_mutex);
    }
    pthread_mutex_t* getMutex()
    {
        return &_mutex;
    }
private:
    pthread_mutex_t _mutex;
    MutexLock(const MutexLock &rhs);
    MutexLock& operator=(const MutexLock &rhs);
};

class Condition
{
public:
    Condition(MutexLock &mutex)
    :_mutex(mutex)
    {
        pthread_cond_init(&_condition,NULL);
    }
    Condition(const Condition & rhs) = delete;
    Condition & operator=(const Condition & rhs) = delete;
    ~Condition()
    {
        pthread_cond_destroy(&_condition);
    }
    void wait()
    {
        pthread_cond_wait(&_condition,_mutex.getMutex());
    }
    void notify()
    {
        pthread_cond_signal(&_condition);
    }
    void notifyall()
    {
        pthread_cond_broadcast(&_condition);
    }
private:
    pthread_cond_t _condition;
    MutexLock &_mutex;
};

class MutexLockGuard
{
public:
    MutexLockGuard(MutexLock &mutex)
    :_mutex(mutex)
    {
        _mutex.lock();
    }
    ~MutexLockGuard()
    {
        _mutex.unlock();
    }
private:
    MutexLock &_mutex;
};
