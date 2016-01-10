#include "thread.h"
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

pthread_t Thread_Net;
pthread_cond_t Cond_Net;
pthread_mutex_t Mutex_Net;
sem_t Sem_Net;
void * Func_Thread_Net(void *argv);

pthread_t Thread_Print;
pthread_cond_t Cond_Print;
pthread_mutex_t Mutex_Print;
sem_t Sem_Print;
void * Func_Thread_Print(void *argv);

void thread_init()
{
	

	pthread_mutex_init(&Mutex_Net, NULL);
	pthread_mutex_init(&Mutex_Print, NULL);

	pthread_cond_init(&Cond_Net, NULL);
	pthread_cond_init(&Cond_Print, NULL);

    sem_init(&Sem_Net, 0, 1);
    sem_init(&Sem_Print, 0, 0);
    
    pthread_create( &Thread_Net, NULL, Func_Thread_Net, NULL);
	pthread_create( &Thread_Print, NULL, Func_Thread_Print, NULL);
	
}

void *Func_Thread_Net(void * argv)
{
    while(1)
    {
        printf("in Net Thread\n");
        pthread_mutex_lock(&Mutex_Net);
        sem_wait(&Sem_Net);
        sem_wait(&Sem_Print);
        //pthread_cond_wait( &Cond_Net, &Mutex_Net);
        printf("Net\n");
        sleep(1);
        //pthread_cond_signal(&Cond_Net);
        pthread_mutex_unlock(&Mutex_Net);
        
        //sem_wait(&Sem_Net);
        sem_post(&Sem_Print);
        sem_post(&Sem_Net);
        //sleep(1);
    }

}
void *Func_Thread_Print(void * argv)
{
    while(1)
    {
        printf("in Print Thread\n");
        pthread_mutex_lock(&Mutex_Net);
        
        sem_wait(&Sem_Print);
        sem_wait(&Sem_Net);
        //pthread_cond_wait( &Cond_Net, &Mutex_Net);
        printf("print\n");
        sleep(1);
        //pthread_cond_signal(&Cond_Net);
        pthread_mutex_unlock(&Mutex_Net);
        
        //sem_wait(&Sem_Print);
        sem_post(&Sem_Net);
        sem_post(&Sem_Print);
        //sleep(1);
    }

}
void UnSem()
{   
    //printf("set net\n");
    //sem_post(&Sem_Net);
    //sleep(1);
    
    printf("set print\n");
    sem_post(&Sem_Print);
    sleep(1);
}