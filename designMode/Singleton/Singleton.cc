#include "Singleton.h"
#include <iostream>

using std::cout;
using std::endl;

Singleton* Singleton::_pInstance = nullptr;
pthread_once_t Singleton::_pthreadOnce = PTHREAD_ONCE_INIT;

Singleton::Singleton()
{
    cout << "Singleton()" << endl;
}

Singleton::~Singleton()
{
    cout << "~Singleton()" << endl;
}

void Singleton::destroy()
{
    if(_pInstance)
    {
        delete _pInstance;
        _pInstance = nullptr;
    }
}

void Singleton::init()
{
    _pInstance = new Singleton();
    atexit(destroy);
}

Singleton* Singleton::getpInstance()
{
    pthread_once(&_pthreadOnce, init);
    return _pInstance;
}