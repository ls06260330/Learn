#include <iostream>
#include <pthread.h>

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void *ThreadFunc1(void *args)
{
    pthread_mutex_lock(&mutex1);
    std::cout << "mutex1 used" << std::endl;
    pthread_mutex_lock(&mutex2);
    std::cout << "mutex2 request..." << std::endl;
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);

    std::cout << "ThreadFunc1 finished" << std::endl;
    pthread_exit(nullptr);
}

void *ThreadFunc2(void *args)
{
    pthread_mutex_lock(&mutex2);
    std::cout << "mutex2 used" << std::endl;
    pthread_mutex_lock(&mutex1);
    std::cout << "mutex1 request..." << std::endl;
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);

    std::cout << "ThreadFunc2 finished" << std::endl;
    pthread_exit(nullptr);
}

int main(int argc, char *argv[])
{
    pthread_t tid1;
    pthread_t tid2;

    pthread_mutex_init(&mutex1, nullptr);
    pthread_mutex_init(&mutex2, nullptr);

    pthread_create(&tid1, nullptr, ThreadFunc1, nullptr);
    pthread_create(&tid2, nullptr, ThreadFunc2, nullptr);

    pthread_join(tid1, nullptr);
    pthread_join(tid2, nullptr);

    return 0;
}