#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include <pthread.h>

class Singleton
{

public:
    static void destroy();
    static void init();
    static Singleton * getpInstance();
private:
    Singleton();
    ~Singleton();

private:
    static Singleton *_pInstance;
    static pthread_once_t _pthreadOnce;
};

#endif