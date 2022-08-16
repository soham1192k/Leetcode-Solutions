#include <semaphore.h>
class FooBar{
private:
    int n;
    sem_t foo_sem,bar_sem;
public:
    FooBar(int n) {
        this->n = n;
        sem_init(&foo_sem,0,1);
        sem_init(&bar_sem,0,0);
    }
    ~FooBar(){
        sem_destroy(&foo_sem);
        sem_destroy(&bar_sem);
    }
    void foo(function<void()> printFoo) {
        for(int i=0;i<n;i++){
            sem_wait(&foo_sem);
        	printFoo();
            sem_post(&bar_sem);
        }
    }
    void bar(function<void()> printBar) {
        for(int i=0;i<n;i++){
            sem_wait(&bar_sem);
        	printBar();
            sem_post(&foo_sem);
        }
    }
};