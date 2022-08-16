#include <semaphore.h>
class DiningPhilosophers {
public:
    vector<sem_t>v;
    DiningPhilosophers() {
        v.resize(5);
        for(int i=0;i<5;i++) sem_init(&v[i],0,1);  
    }
    ~DiningPhilosophers(){
        for(int i=0;i<5;i++) sem_destroy(&v[i]);
    }
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int left=philosopher;
        int right=(philosopher+1)%5;
        if(philosopher&1){
            sem_wait(&v[left]);
            sem_wait(&v[right]);
            pickLeftFork();
            pickRightFork();
        }
        else{
            sem_wait(&v[right]);
            sem_wait(&v[left]);
            pickRightFork();
            pickLeftFork();
        }
        eat();
        putLeftFork();
        putRightFork();
        sem_post(&v[left]);
        sem_post(&v[right]);
    }
};