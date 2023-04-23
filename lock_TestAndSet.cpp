#include <iostream>
#include <pthread.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct lock_t{
    int flag;
}lock_t;

void init(lock_t *lock){
    lock -> flag = 0;
}

int TestAndSet(int *old_ptr, int new_t){
    int old = *old_ptr;
    *old_ptr = new_t;
    return old;
}

void lock(lock_t *lock){
    while(TestAndSet(&lock -> flag, 1) == 1)
    ; // spin - wait (do nothing)
}

void unlock(lock_t *lock){
    lock -> flag = 0;
}

int main(){

    return 0;
}