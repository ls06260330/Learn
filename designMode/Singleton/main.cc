#include "Singleton.h"
#include <iostream>
#include <memory>

using std::shared_ptr;
using std::endl;
using std::cout;

int main(int argc, char *argv[])
{
    Singleton *ptr = Singleton::getpInstance();
    /* shared_ptr<Singleton> ptr(Singleton::getpInstance()); */
    cout << "main()" << endl;

    return 0;
}