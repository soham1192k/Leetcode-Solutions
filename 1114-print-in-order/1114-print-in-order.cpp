#include <semaphore.h>
class Foo {
public:
    sem_t s1,s2;
    Foo() {
        sem_init(&s1,0,0);
        sem_init(&s2,0,0);
    }
    void first(function<void()> printFirst) {   
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&s1);
    }
    void second(function<void()> printSecond) {
        sem_wait(&s1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&s2);
    }
    void third(function<void()> printThird) {
        sem_wait(&s2);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};