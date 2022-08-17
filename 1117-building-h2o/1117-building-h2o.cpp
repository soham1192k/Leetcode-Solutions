#include <semaphore.h>
class H2O {
private:
    sem_t hyd_sem,oxy_sem;
    sem_t mutex;
    int h;
public:
    H2O() {
        this->h=0;
        sem_init(&hyd_sem,0,1);
        sem_init(&oxy_sem,0,0);
        sem_init(&mutex,0,1);
    }
    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&hyd_sem);
        sem_wait(&mutex);
        this->h++;
        sem_post(&mutex);
        releaseHydrogen();
        if(h%2) sem_post(&hyd_sem);
        else sem_post(&oxy_sem);
    }
    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&oxy_sem);
        releaseOxygen();
        sem_post(&hyd_sem);
    }
};