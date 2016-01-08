#include "thread.h"
#include 


pthread_t Thread_Net;
pthread_cond_t Thread_Net_Cond;
pthread_mutex_t Thread_Net_Mutex;
void * Func_Thread_Net(void *argv);

pthread_t Thread_Print;
pthread_cond_t Thread_Print_Cond;
pthread_mutex_t Thread_Print_Mutex;
void * Func_Thread_Print(void *argv);

void thread_init()
{
	pthread_create( Thread_Net, NULL, Func_Thread_Net, NULL);
	pthread_create( Thread_Print, NULL, Func_Thread_Print(), NULL);

	

}
